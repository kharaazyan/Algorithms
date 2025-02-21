#include <iostream>
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

int main() {
    std::vector<float> data = { 5, 2, 9, 1, 7, 24, -605, 128, 5, 28, 34, -65};
    
    std::cout << "Before Sorting: ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    insertionSort(data);
    
    std::cout << "After Sorting:  ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
