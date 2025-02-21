#include <iostream>
#include <vector>

template<typename T>
int binarySearchIterative(const std::vector<T>& arr, T target) {
    size_t left = 0;
    size_t right = arr.size() - 1;
    
    while (left <= right) {
        size_t mid = left + (right - left) / 2; 
        if(arr[mid] == target) return mid;
        else if(target > arr[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1; 
}

template<typename T>
int binarySearchRecursive(const std::vector<T>& arr, size_t left, size_t right, T target) {
    if (left > right) return -1;
    size_t mid = left + (right - left) / 2;
    
    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) return binarySearchRecursive(arr, mid + 1, right, target);
    else return binarySearchRecursive(arr, left, mid - 1, target);
}

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 13};
    int target = 1;
    int index = binarySearchIterative(data, 13);
    
    if (index != -1) {
        std::cout << "Element " << target << " was found on position " << index << std::endl;
    }
    else {
        std::cout << "Element " << target << " wasn't found." << std::endl;
    }
}
