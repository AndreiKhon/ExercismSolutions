#if !defined(DIFFERENCE_OF_SQUARES_H)
#define DIFFERENCE_OF_SQUARES_H
#include <cstddef>
namespace difference_of_squares {
    inline size_t square_of_sum(size_t n) {
        size_t progretion_sum = (1 + n) * n / 2;
        return progretion_sum * progretion_sum;
    }
    inline size_t sum_of_squares(size_t n) {
        return n * (n + 1) * (2 * n + 1) / 6;
    }
    inline size_t difference(size_t n) {
        return square_of_sum(n) - sum_of_squares(n);
    }
}  // namespace difference_of_squares

#endif // DIFFERENCE_OF_SQUARES_H