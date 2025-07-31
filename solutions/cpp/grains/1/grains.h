#if !defined(GRAINS_H)
#define GRAINS_H
#include <cstdint>
#include <cmath>
namespace grains {
    inline uint64_t square(uint32_t sq) {
        return std::pow(2, sq - 1);
    }
    inline uint64_t total() {
        constexpr auto boardLength = 64;
        constexpr auto multiplier = 2;
        constexpr auto firstGrainCount = 1;
        return static_cast<uint64_t>(firstGrainCount * (1 - pow(multiplier, boardLength)) / (1 - multiplier));
    }
}  // namespace grains

#endif // GRAINS_H