package com.ozacmaonv.goddess.wardrobe;

import android.app.Application;
import android.os.AsyncTask;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import java.util.List;

public class ClothingRepository {

    private ClothingDao clothingDao;
    private LiveData<List<ClothingEntity>> allClothingItems;

    public ClothingRepository(Application application) {
        ClothingDatabase database = ClothingDatabase.getInstance(application);
        clothingDao = database.clothingDao();
        allClothingItems = clothingDao.getAllClothing();
    }
    public LiveData<List<ClothingEntity>> getAllClothingItems() {
        return allClothingItems;
    }

    public void insertClothingItem(ClothingEntity clothingEntity) {
        new InsertClothingItemAsyncTask(clothingDao).execute(clothingEntity);
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
        new DeleteClothingItemAsyncTask(clothingDao).execute(clothingEntity);
    }

    private static class DeleteClothingItemAsyncTask extends AsyncTask<ClothingEntity, Void, Void> {
        private ClothingDao clothingDao;

        private DeleteClothingItemAsyncTask(ClothingDao clothingDao) {
            this.clothingDao = clothingDao;
        }

        @Override
        protected Void doInBackground(ClothingEntity... clothingEntities) {
            clothingDao.delete(clothingEntities[0]);
            return null;
        }
    }

    public void updateClothingItem(ClothingEntity clothingEntity, MutableLiveData<Boolean> updateResultLiveData) {
        // 将updateResultLiveData传递给AsyncTask，以便在更新完成后更新LiveData
        new UpdateClothingItemAsyncTask(clothingDao, updateResultLiveData).execute(clothingEntity);
    }

    private static class UpdateClothingItemAsyncTask extends AsyncTask<ClothingEntity, Void, Boolean> {
        private ClothingDao clothingDao;
        private MutableLiveData<Boolean> updateResultLiveData;

        private UpdateClothingItemAsyncTask(ClothingDao clothingDao, MutableLiveData<Boolean> updateResultLiveData) {
            this.clothingDao = clothingDao;
            this.updateResultLiveData = updateResultLiveData;
        }

        @Override
        protected Boolean doInBackground(ClothingEntity... clothingEntities) {
            clothingDao.update(clothingEntities[0]);
            return true;
        }

        @Override
        protected void onPostExecute(Boolean result) {
            super.onPostExecute(result);
//            updateResultLiveData.setValue(result);
            // 在更新完成后，使用updateResultLiveData通知结果
            updateResultLiveData.setValue(true);
        }
    }
}
