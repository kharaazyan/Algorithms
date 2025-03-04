#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <vector>

template <typename T>
void insertionSort(std::vector<T>& arr){
    int size = arr.size();
    for(int i = 1; i < size; ++i){
        T key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
#endif