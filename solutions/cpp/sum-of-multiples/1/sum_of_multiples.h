#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H
#include <unordered_set>
#include <cstddef>
#include <numeric>
namespace sum_of_multiples {
    inline size_t to(std::initializer_list<size_t> multipliers, size_t n) {
        std::unordered_set<size_t> multiples_map;
        for(auto mul: multipliers) {
            auto mul_ = mul;
            while(mul < n) {
                multiples_map.insert(mul);
                mul += mul_;
            }
        }
        return std::accumulate(multiples_map.begin(), multiples_map.end(), 0);
    }
}  // namespace sum_of_multiples

#endif // SUM_OF_MULTIPLES_H