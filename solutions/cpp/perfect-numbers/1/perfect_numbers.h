#if !defined(PERFECT_NUMBERS_H)
#define PERFECT_NUMBERS_H
#include <cstdio>
namespace perfect_numbers {
    enum perfect_numbers {
        perfect,
        abundant,
        deficient
    };

    perfect_numbers classify(int number);
}  // namespace perfect_numbers

#endif  // PERFECT_NUMBERS_H