#ifndef QUICK_SELECT
#define QUICK_SELECT

#include <vector>
#include <ctime>
#include <cstdlib>

template<typename T>
int partition(std::vector<T>& data, int left, int right){
    int pivot = left + rand() % (right - left + 1);
    std::swap(data[pivot], data[right]);

    int i = left - 1;
    for(int j = left; j < right; ++j){
        if(data[j] < data[right]) std::swap(data[++i], data[j]);
    }
    std::swap(data[++i], data[right]);
    return i;
}

template<typename T>
T quickSelect(std::vector<T>& data, int left, int right, int k){
    if(left == right) return data[left];
    srand(time(NULL));

    int pivot = partition(data, left, right);
    int count = pivot - left + 1;
    
    if(count == k) return data[pivot];
    else if(k < count) return quickSelect(data, left, pivot - 1, k);
    else return quickSelect(data, pivot + 1, right, k - count);
}
#endif