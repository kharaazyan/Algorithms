#ifndef BUCKET_SORT
#define BUCKET_SORT

#include <iostream>
#include <vector>

void insertionSort(std::vector<float>&  arr){
    int size = arr.size();
    for(int i = 1; i < size; ++i){
        float key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(std::vector<float>& arr) {
    int size = arr.size();
    if(size <= 0) return;

    int numBuckets = 10;
    std::vector<std::vector<float>> buckets(numBuckets);

    for(int i = 0; i < size; ++i){
        int bucketIndex = arr[i] * numBuckets;
        if(bucketIndex >= numBuckets) bucketIndex = numBuckets - 1; 
        buckets[bucketIndex].push_back(arr[i]);
    }

    for(int i = 0; i < numBuckets; ++i){
        insertionSort(buckets[i]);
    }

    int index = 0;
    for(int i = 0; i < numBuckets; ++i){
        for(int j = 0; j < buckets[i].size(); ++j){
            arr[index++] = buckets[i][j];
        }
    }
}
#endif