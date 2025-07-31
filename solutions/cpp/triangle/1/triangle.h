#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
    enum class flavor {
        scalene = 0,
        isosceles = 1,
        equilateral = 3
    };

    template<class T, class Y, class U>
    flavor kind(T side1, Y side2, U side3) {
        if(!(side1 && side2 && side3))
            throw(std::domain_error(""));
        if(side1 + side2 < side3)
            throw(std::domain_error(""));
        if(side1 + side3 < side2)
            throw(std::domain_error(""));
        if(side2 + side3 < side1)
            throw(std::domain_error(""));
        auto eq1 = side1 == side2;
        auto eq2 = side2 == side3;
        auto eq3 = side3 == side1;
        return static_cast<flavor>(eq1 + eq2 + eq3);
    }
}  // namespace triangle

#endif // TRIANGLE_H