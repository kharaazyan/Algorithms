#include <iostream>
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

int main() {
    std::vector<int> data = { 5, 2, 9, 1, 7, 24, -605, 128, 5, 28, 34, -65};
    
    std::cout << "Before Sorting: ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    selectionSort(data);
    
    std::cout << "After Sorting:  ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
