#if !defined(HAMMING_H)
#define HAMMING_H
#include <string_view>
#include <cstddef>
namespace hamming {
    std::size_t compute(std::string_view first, std::string_view second);
}  // namespace hamming

#endif // HAMMING_H