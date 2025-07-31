#if !defined(BINARY_SEARCH_H)
#define BINARY_SEARCH_H
#include <cstddef>
#include <vector>
#include <stdexcept>
namespace binary_search {
    template <typename T>
    ssize_t find(const std::vector<T>& data, T value) {
        ssize_t left = 0;
        ssize_t right =  data.size() - 1;
        while(left <= right) {
            auto mid = left + (right - left) / 2;
            if(data[mid] == value)
                return mid;
            if(data[mid] < value)
                left = mid + 1;
            if(data[mid] > value)
                right = mid - 1;
        }
        throw(std::domain_error("No value in vector"));
    }
}  // namespace binary_search

#endif // BINARY_SEARCH_H