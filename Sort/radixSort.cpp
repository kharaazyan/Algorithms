#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr, int exp){
    int count[10] = {0};
    int size = arr.size();
    std::vector<int> output(size, 0);

    for(int i = 0; i < size; ++i){
        int digit = (arr[i] / exp) % 10;
        ++count[digit];
    }

    for(int i = 1; i < 10; ++i){
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; --i){
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        --count[digit];
    }

    for(int i = 0; i < size; ++i){
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr){
    int max = *std::max_element(arr.begin(), arr.end());

    for(int exp = 1; max / exp > 0; exp *= 10){
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> data = { 5, 2, 9, 1, 7, 24, 605, 128, 5, 28, 34, 65231, 2441412, 42, 6654};
    
    std::cout << "Before Sorting: ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    radixSort(data);
    
    std::cout << "After Sorting:  ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
