#ifndef QUICK_SORT
#define QUICK_SORT

#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
int partitionLast(std::vector<T> &arr, int low, int high){
    T pivot = arr[high];

    int i = low - 1;
    for (int j = low; j < high; ++j){
        if (arr[j] < pivot){
            ++i;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSortLast(std::vector<T> &arr, int low, int high){
    if (low < high){
        int pivot = partitionLast(arr, low, high);

        quickSortLast(arr, low, pivot - 1);
        quickSortLast(arr, pivot + 1, high);
    }
}

template <typename T>
int partitionFirst(std::vector<T> &arr, int low, int high){
    T pivot = arr[low];

    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (arr[i] < pivot);

        do
        {
            --j;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        std::swap(arr[i], arr[j]);
    }
}

template <typename T>
void quickSortFirst(std::vector<T> &arr, int low, int high){
    if (low < high)
    {
        int pivot = partitionFirst(arr, low, high);

        quickSortFirst(arr, low, pivot);
        quickSortFirst(arr, pivot + 1, high);
    }
}

template <typename T>
void quickSortRand(std::vector<T> &arr, int low, int high){
    if (low < high)
    {
        int random = low + rand() % (high - low + 1);
        std::swap(arr[high], arr[random]);
        int pivot = partitionLast(arr, low, high);

        quickSortLast(arr, low, pivot - 1);
        quickSortLast(arr, pivot + 1, high);
    }
}

template <typename T>
void medianOfThree(std::vector<T> &arr, int low, int high){
    int mid = low + (high - low) / 2;

    if(arr[low] > arr[mid]) std::swap(arr[low], arr[mid]);
    if(arr[low] > arr[high]) std::swap(arr[low], arr[high]);
    if(arr[mid] > arr[high]) std::swap(arr[mid], arr[high]);

    std::swap(arr[mid], arr[high]);
}

template <typename T>
void quickSortMediana(std::vector<T> &arr, int low, int high){
    if (low < high)
    {
        medianOfThree(arr, low, high);
        int pivot = partitionLast(arr, low, high);

        quickSortLast(arr, low, pivot - 1);
        quickSortLast(arr, pivot + 1, high);
    }
}
#endif