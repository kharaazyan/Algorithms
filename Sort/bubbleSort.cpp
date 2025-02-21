#include <iostream>
#include <iterator> 
#include <vector>

template <typename Iterator>
void bubbleSort(Iterator begin, Iterator end) {
    if (begin == end) return;
    Iterator tmp = end;
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = begin; std::next(j) != tmp; ++j) {
            if (*j > *std::next(j)) {
                std::iter_swap(j, std::next(j)); 
            }
        }
        --tmp; 
    }
}

template<typename T>
void bubbleSort(std::vector<T>& vec){
    for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec.size() - 1 - i; ++j){
            if(vec[i] > vec[i + 1]) std::swap(vec[i], vec[i + 1]);
        }
    }
}


int main() {
    std::vector<float> data = { 5, 2, 9, 1, 7, 24, -605, 128, 5, 28, 34, -65, 12,421,12,4,214,214,21,4,214,21,412,-642};
    
    std::cout << "Before Sorting: ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    bubbleSort(data.begin(), data.end());
    bubbleSort(data);
    
    std::cout << "After Sorting:  ";
    for (auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}