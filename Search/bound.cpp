#include <iostream>
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

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 7, 8};
    int value = 4;
    
    int lb = my_lower_bound(v, value);
    int ub = my_upper_bound(v, value);
    
    std::cout << "lower_bound для " << value << " находится на позиции: " << lb << "\n";
    std::cout << "upper_bound для " << value << " находится на позиции: " << ub << "\n";
    
    int count = ub - lb;
    std::cout << "Количество элементов равных " << value << ": " << count << "\n";
    
    return 0;
}
