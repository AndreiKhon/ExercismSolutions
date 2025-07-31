#include "hamming.h"
#include <stdexcept>
#include <numeric>
namespace hamming {
    std::size_t compute(std::string_view first, std::string_view second) {
        if(first.size() != second.size())
            throw std::domain_error("");
        return std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<>(), std::not_equal_to<>());
    }

}  // namespace hamming
