#ifndef COUNTING_SORT
#define COUNTING_SORT

#include <vector> 
#include <algorithm>

template <typename T>
void countingSort(std::vector<T> &arr){
    auto [minIt, maxIt] = std::minmax_element(arr.begin(), arr.end());
    T min = *minIt, max = *maxIt;

    int range = max - min + 1;
    std::vector<T> output(arr.size());
    std::vector<int> sum(range, 0);

    for(auto &i : arr){
        ++sum[i - min];
    }

    for(int i = 1; i < sum.size(); ++i){
        sum[i] += sum[i - 1];
    }

    for(int i = arr.size() - 1; i >= 0; --i){
        output[sum[arr[i] - min] - 1] = arr[i];
        --sum[arr[i] - min];
    }

    arr = std::move(output);
}
#endif