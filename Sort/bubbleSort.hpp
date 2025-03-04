#ifndef BUBBLE_SORT
#define BUBBLE_SORT

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

#endif
