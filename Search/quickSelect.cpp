#include <iostream>
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

    int pivot = partition(data, left, right);
    int count = pivot - left + 1;
    
    if(count == k) return data[pivot];
    else if(k < count) return quickSelect(data, left, pivot - 1, k);
    else return quickSelect(data, pivot + 1, right, k - count);
}

int main() {
    srand(time(NULL));
    std::vector<int> data = {9,6,3,2,7,1,4,5,10, 8};
    int target = 1;
    std::cout << "Before: ";
    for(auto i : data){
        std::cout << i << " ";
    }
    int value = quickSelect(data, 0, data.size() - 1, 7);
    std::cout << std::endl << "After: ";
    for(auto i : data){
        std::cout << i << " ";
    }
    std::cout << std::endl << "pivot: " << value << std::endl;
}