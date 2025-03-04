#ifndef BOUND
#define BOUND
#include <vector>

int my_lower_bound(const std::vector<int>& v, int value) {
    int left = 0;
    int right = v.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (v[mid] < value) left = mid + 1;
        else right = mid;
    }
    return left;
}

int my_upper_bound(const std::vector<int>& v, int value) {
    int left = 0;
    int right = v.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (v[mid] <= value)
            left = mid + 1;
        else
            right = mid;
    return left;
    }   
}
#endif