#include "binary_insertion_sort.h"

template <typename T>
void binary_insertion_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    for (std::size_t i = 1; i < n; ++i) {
        const T key = arr[i];

        std::size_t low = 0;
        std::size_t high = i;
        while (low < high) {
            const std::size_t mid = low + (high - low) / 2;
            if (arr[mid] > key) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        for (std::size_t j = i; j > low; --j) {
            arr[j] = arr[j - 1];
        }
        arr[low] = key;
    }
}

template void binary_insertion_sort<int>(std::vector<int>&);
template void binary_insertion_sort<double>(std::vector<double>&);
template void binary_insertion_sort<float>(std::vector<float>&);
