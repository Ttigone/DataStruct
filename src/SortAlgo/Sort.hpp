#include <iostream>

#include <vector>


namespace mysort{

namespace selection {

template <typename T>
void select_sort(T a[], int n) {
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
void select_sort(std::vector<T> vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec.at(j) < vec.at(min_index)) {
                min_index = j;
            }
        }
    }
}

} // selection


} // mysort

