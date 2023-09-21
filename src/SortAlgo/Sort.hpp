#include <iostream>

#include <vector>

namespace mysort{

namespace Insert {

namespace insertSort {

} // insertSort

namespace binInsertSort {

} // binInsertSort

namespace shellSort {

} // shellSort


} // Insert

namespace Exchange {

namespace bubbleSort {
    template<typename T>
    void Sort(T a[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    std::swap(a[i], a[j]);
                }
            }
        }
    }

} // bubbleSort

namespace quickSort {

} // quickSort

} // Exchange

namespace Selection {

namespace selectSort {

template <typename T>
void Sort(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
    }
}

template<typename T>
void sort(std::vector<T> vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec.at(j) < vec.at(min_index)) {
                min_index = j;
            }
        }
    }
}

} // selectSort

namespace heapSort {

} // heapSort

} // Selection

namespace Merge {

namespace mergeSort{

} // mergeSort

} // Merge

namespace Radix {
namespace radixSort{
} // radixSort

} // Radix


} // mysort

