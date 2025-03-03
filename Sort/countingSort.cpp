#include <iostream>
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

    for(int i = 0; i < arr.size(); ++i){
        arr[i] = output[i];
    }
}

int main() {
    //std::vector<float> data = { 5, 2, 9, 1, 7, 24, -605, 128, 5, 28, 34, -65, 12,421,12,4,214,214,21,4,214,21,412,-642};
    std::vector<float> data = {5, 2, -1, 7,4, 4, 4};
    
    std::cout << "Before Sorting: ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    countingSort(data);
    
    std::cout << "After Sorting:  ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}