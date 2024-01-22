package com.ozacmaonv.goddess.wardrobe;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class ClothingListFragment extends Fragment {

    private List<ClothingEntity> clothingList;
    private ClothingAdapter adapter;
    private ClothingViewModel clothingViewModel;
    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        // 创建 ClothingViewModel 的实例
        clothingViewModel = new ViewModelProvider(this).get(ClothingViewModel.class);

        // 添加观察者以观察数据变化
        clothingViewModel.getAllClothingItems().observe(getViewLifecycleOwner(), new Observer<List<ClothingEntity>>() {
            @Override
            public void onChanged(List<ClothingEntity> clothingEntities) {
                // 当数据发生变化时更新UI
                clothingList.clear();
                clothingList.addAll(clothingEntities);
                adapter.notifyDataSetChanged();
            }
        });

        // 添加观察者以观察更新结果
        clothingViewModel.getUpdateResultLiveData().observe(getViewLifecycleOwner(), new Observer<Boolean>() {
            @Override
            public void onChanged(Boolean updateResult) {
                if (updateResult) {
                    // 更新成功
                    Toast.makeText(requireContext(), "Update successful", Toast.LENGTH_SHORT).show();
                    // 这里可以添加其他更新成功后的操作
                } else {
                    // 更新失败
                    Toast.makeText(requireContext(), "Update failed", Toast.LENGTH_SHORT).show();
                    // 这里可以添加其他更新失败后的操作
                }
            }
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_clothing_list, container, false);

        RecyclerView recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        // 创建 ClothingViewModel 的实例
        clothingViewModel = new ViewModelProvider(this).get(ClothingViewModel.class);
        clothingList = new ArrayList<>();
        adapter = new ClothingAdapter(clothingList, clothingViewModel);
        recyclerView.setAdapter(adapter);

        // 使用异步任务加载数据
        LoadDataTask loadDataTask = new LoadDataTask();
        loadDataTask.execute();
        // 找到按钮
        Button buttonAddClothing = view.findViewById(R.id.buttonAddClothing);
        // 添加点击监听器
        buttonAddClothing.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行跳转到添加衣物的界面的操作
                // 启动添加衣物的Activity
                Intent intent = new Intent(getActivity(), AddClothingActivity.class);
                startActivity(intent);
                // 例如，启动一个新的Activity或Fragment
                // Intent intent = new Intent(getActivity(), AddClothingActivity.class);
                // startActivity(intent);

                // 如果使用Fragment，可以使用FragmentManager启动一个新的Fragment
                // FragmentManager fragmentManager = requireActivity().getSupportFragmentManager();
                // FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
                // fragmentTransaction.replace(R.id.fragment_container, new AddClothingFragment());
                // fragmentTransaction.addToBackStack(null);
                // fragmentTransaction.commit();
            }
        });

        // 找到返回按钮
        Button buttonBack = view.findViewById(R.id.buttonBack);
        // 添加点击监听器
        buttonBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 返回主界面
                requireActivity().onBackPressed();
            }
        });
        return view;
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();

        // 显示按钮
        Button buttonShowClothing = requireActivity().findViewById(R.id.buttonShowClothing);
        buttonShowClothing.setVisibility(View.VISIBLE);
    }

    // 异步任务用于加载数据
    private class LoadDataTask extends AsyncTask<Void, Void, List<ClothingEntity>> {

        @Override
        protected List<ClothingEntity> doInBackground(Void... voids) {
            // 从数据库或其他数据源加载数据
            // 这里只是一个示例，你需要替换为实际的加载数据的代码
            // Assuming you have access to the application context
            // Assuming you are in a Fragment or Activity

            // 注意：这里调用的是 getValue() 方法来获取 LiveData 的值
            List<ClothingEntity> data = ClothingDatabase.getInstance(requireContext()).clothingDao().getAllClothing().getValue();

            // 确保数据不为 null
            if (data == null) {
                data = new ArrayList<>();  // 或者你可以根据实际情况采取其他处理方式
            }

            return data;
        }

        @Override
        protected void onPostExecute(List<ClothingEntity> result) {
            super.onPostExecute(result);

            // 加载完成后更新数据集并通知适配器
            clothingList.clear();
            clothingList.addAll(result);
            adapter.notifyDataSetChanged();
        }
    }
}
