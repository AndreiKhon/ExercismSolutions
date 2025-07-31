#include "hamming.h"
#include <stdexcept>
namespace hamming {
    std::size_t compute(std::string_view first, std::string_view second) {
        size_t difference = 0;
        if( first.size() != second.size())
            throw std::domain_error("");
        for(size_t i = 0; i < first.size(); ++i)
            if(first[i] != second[i])
                ++difference;
        return difference;
    }

}  // namespace hamming
