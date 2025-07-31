#if !defined(COLLATZ_CONJECTURE_H)
#define COLLATZ_CONJECTURE_H
#include <cstddef>
#include <stdexcept>
namespace collatz_conjecture {
    inline size_t steps(ssize_t value) {
        if(value <= 0)
            throw std::domain_error("");
        size_t steps_ = 0;
        while(value != 1) {
            value = value % 2 ? value * 3 + 1 : value / 2;
            ++steps_;
        }
        return steps_;
    }
}  // namespace collatz_conjecture

#endif // COLLATZ_CONJECTURE_H