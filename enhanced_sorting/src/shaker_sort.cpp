#include "shaker_sort.h"

template <typename T>
void shaker_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    std::size_t left = 0;
    std::size_t right = n - 1;
    bool swapped = true;

    while (left < right && swapped) {
        swapped = false;

        for (std::size_t i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        --right;

        for (std::size_t i = right; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        ++left;
    }
}

template void shaker_sort<int>(std::vector<int>&);
template void shaker_sort<double>(std::vector<double>&);
template void shaker_sort<float>(std::vector<float>&);
