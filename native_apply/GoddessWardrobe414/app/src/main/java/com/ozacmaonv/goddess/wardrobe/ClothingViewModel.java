package com.ozacmaonv.goddess.wardrobe;

import android.app.Application;
import android.os.AsyncTask;
import android.util.Log;

import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import java.util.List;

public class ClothingViewModel extends AndroidViewModel {

    private ClothingRepository clothingRepository;
    private LiveData<List<ClothingEntity>> allClothingItems;
    // 新增用于通知更新结果的LiveData
    private MutableLiveData<Boolean> updateResultLiveData = new MutableLiveData<>();
    public ClothingViewModel(Application application) {
        super(application);
        clothingRepository = new ClothingRepository(application);
        allClothingItems = clothingRepository.getAllClothingItems();
    }

    public LiveData<List<ClothingEntity>> getAllClothingItems() {
        return allClothingItems;
    }

    // 获取用于通知更新结果的LiveData
    public MutableLiveData<Boolean> getUpdateResultLiveData() {
        return updateResultLiveData;
    }

    public void insertClothingItem(ClothingEntity clothingEntity) {
        clothingRepository.insertClothingItem(clothingEntity);
    }

    private static class InsertClothingItemAsyncTask extends AsyncTask<ClothingEntity, Void, Void> {
        private ClothingDao clothingDao;

        private InsertClothingItemAsyncTask(ClothingDao clothingDao) {
            this.clothingDao = clothingDao;
        }

        @Override
        protected Void doInBackground(ClothingEntity... clothingEntities) {
            clothingDao.insert(clothingEntities[0]);
            return null;
        }
    }

    public void deleteClothingItem(ClothingEntity clothingEntity) {
        clothingRepository.deleteClothingItem(clothingEntity);
    }

    public void updateClothingItem(ClothingEntity clothingEntity) {
        // 在这里调用更新方法时，将updateResultLiveData传递给repository
        clothingRepository.updateClothingItem(clothingEntity, updateResultLiveData);
    }
}
