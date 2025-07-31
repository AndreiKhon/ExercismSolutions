#include "complex_numbers.h"
#include <set>
#include <unordered_set>
namespace complex_numbers::some_tests {
    constexpr Complex c0;
    static_assert(c0.real() == 0);
    
    constexpr Complex c1{15, 25}; 
    static_assert(c1.real() == 15);

    constexpr Complex c2{25};
    constexpr auto sum_c = c1 + c2;
    static_assert(sum_c.real() == 40);

    constexpr Complex c3 = 1 + c2;
    static_assert(c3.real() == 26);

    std::set<Complex> complex_set{c3, c2};
    std::unordered_set<Complex> complex_hash{c3, c2};

    using namespace complex_numbers::literals; 
    constexpr auto literal_complex = 1 + 25_i;
    static_assert(static_cast<int>(literal_complex.imag()) == 25);

    constexpr auto another_literal_complex = 100 - 100.0_i;
    constexpr auto e = 0.005;
    constexpr auto some_double = another_literal_complex.imag() + 100.0;
    static_assert(some_double < e  && some_double > -e);
}  // namespace complex_numbers::some_tests
