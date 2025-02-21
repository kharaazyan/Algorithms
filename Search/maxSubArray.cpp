#include <iostream>
#include <tuple>
#include <limits>
#include <vector>

template<typename T>
std::tuple<int, int, T> findCross(const std::vector<T>& arr, int low, int mid, int high){
    T leftSum = std::numeric_limits<T>::lowest();
    T sum = 0;
    int leftMax = mid;

    for(int i = mid; i >= low; --i){
        sum += arr[i];
        if(sum > leftSum){
            leftSum = sum;
            leftMax = i;
        }
    }

    T rightSum = std::numeric_limits<T>::lowest();
    int rightMax = mid + 1;
    sum = 0;
    
    for(int i = mid + 1; i <= high; ++i){
        sum += arr[i];
        if(sum > rightSum){
            rightSum = sum;
            rightMax = i;
        }
    }
    
    return std::make_tuple(leftMax, rightMax, leftSum + rightSum);
}

template<typename T>
std::tuple<int, int, T> findMaxDaQ(const std::vector<T>& arr, int low, int high){
    if (low == high) {
        return std::make_tuple(low, high, arr[low]);
    }

    int mid = low + (high - low) / 2;

    std::tuple<int, int, T> leftResult = findMaxDaQ(arr, low, mid);
    std::tuple<int, int, T> rightResult = findMaxDaQ(arr, mid + 1, high);
    std::tuple<int, int, T> crossResult = findCross(arr, low, mid, high);

    T leftSum = std::get<2>(leftResult);
    T rightSum = std::get<2>(rightResult);
    T crossSum = std::get<2>(crossResult);

    if(leftSum >= rightSum && leftSum >= crossSum){
        return leftResult;
    }
    else if(rightSum >= leftSum && rightSum >= crossSum){
        return rightResult;
    }
    else {
        return crossResult;
    }
}

template<typename T>
std::tuple<int, int, T> brutForce(std::vector<T>& arr){
    if(arr.size() == 0) return std::make_tuple(0, 0, 0);
    T maxSum = std::numeric_limits<T>::lowest();
    int size = arr.size();
    int start, end;
    for(int i = 0; i < size; ++i){
        int curSum {0};
        for(int j = i; j < size; ++j){
            curSum += arr[j];
            if(curSum > maxSum){
                maxSum = curSum;
                start = i;
                end = j;
            }
        }
    }
    return std::make_tuple(start, end, maxSum);
}

template<typename T>
std::tuple<int, int, T> kadane(std::vector<T>& arr){
    int size = arr.size();
    if(size == 0) return std::make_tuple(0, 0, 0);

    T maxSum = arr[0], currentSum = arr[0];
    int start, end, tmpStart;

    for(int i = 1; i < size; ++i){
        if(arr[i] > currentSum + arr[i]){
            currentSum = arr[i];
            tmpStart = i;
        }
        else currentSum += arr[i];
        if(currentSum > maxSum){
            maxSum = currentSum;
            start = tmpStart;
            end = i;
        }
    }
    return std::make_tuple(start, end, maxSum);
}

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -54, 4, 5, 3, 5, 4};

    auto[start, end, sum] = findMaxDaQ(arr, 0, arr.size() - 1);

    std::cout << "Максимальная подпоследовательность: " << std::endl;
    std::cout << "Начальный индекс: " << start << std::endl;
    std::cout << "Конечный индекс: " << end << std::endl;
    std::cout << "Сумма: " << sum << std::endl;
}
