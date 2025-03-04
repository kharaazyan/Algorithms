#ifndef SELECTION_SORT
#define SELECTION_SORT
#include <vector>

template <typename T>
void selectionSort(std::vector<T>& arr){
    int size = arr.size();
    for(int i = 0; i < size; ++i){
        int min_index = i;
        for(int j = i + 1; j < size; ++j){
            if(arr[j] < arr[min_index]) min_index = j;
        }
        if(min_index != i) std::swap(arr[min_index], arr[i]);
    }
}

#endif
