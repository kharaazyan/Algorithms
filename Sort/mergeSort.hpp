#ifndef MERGE_SORT
#define MERGE_SORT

#include <vector>

template<typename T>
void merge(std::vector<T>&arr, size_t left, size_t mid, size_t right){
    size_t size1 = mid - left + 1;
    size_t size2 = right - mid;
    
    std::vector<T> aleft(size1), aright(size2);

    for(int i = 0; i < size1; ++i) aleft[i] = arr[i + left];
    for(int i = 0; i < size2; ++i) aright[i] = arr[i + mid + 1];

    int count = left, i = 0, j = 0;
    while(i < size1 && j < size2){
        if(aleft[i] <= aright[j]) arr[count++] = aleft[i++];
        else arr[count++] = aright[j++];
    }

    while(i < size1) arr[count++] = aleft[i++];
    while(j < size2) arr[count++] = aright[j++];
}

template<typename T>
void mergeSort(std::vector<T>& arr, size_t left, size_t right){
    if(left >= right) return;
    size_t mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
#endif