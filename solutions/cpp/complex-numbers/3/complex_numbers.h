#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <cmath>
#include <cstdint>
#include <functional>
#include <limits>
namespace complex_numbers {
class Complex {
    public:
        constexpr Complex(double real = 0, double imagine = 0) : 
            real_(real), imag_(imagine) { 
        }

        [[nodiscard]] constexpr double real() const { 
            return real_;
        } 

        [[nodiscard]] constexpr double imag() const { 
            return imag_; 
        }

        [[nodiscard]] constexpr Complex conj() const { 
            return {real_, -imag_}; 
        }

        [[nodiscard]] Complex exp() const { 
            auto real = std::exp(real_) * std::cos(imag_);
            auto imag = std::exp(real_) * std::sin(imag_);
            return {real, imag};
        }

        [[nodiscard]] double abs() const { 
            return std::hypot(real_, imag_);
        }
private:
        double real_;
        double imag_;
    };

    constexpr Complex operator+(const Complex c1, const Complex c2) { 
        auto real = c1.real() + c2.real();
        auto imag = c1.imag() + c2.imag();
        return {real, imag}; 
    }

    constexpr Complex operator-(const Complex c1, const Complex c2) { 
        auto real = c1.real() - c2.real();
        auto imag = c1.imag() - c2.imag();
        return {real, imag}; 
    }

    constexpr Complex operator*(const Complex c1, const Complex c2) { 
        auto real = c1.real() * c2.real() - c1.imag() * c2.imag();
        auto imag = c1.imag() * c2.real() + c1.real() * c2.imag();
        return {real, imag};
    }
    
    constexpr Complex operator/(const Complex c1, const Complex c2) { 
        auto denominator = c2.real() * c2.real() + c2.imag() * c2.imag();
        auto real = (c1.real() * c2.real() + c1.imag() * c2.imag()) 
        / denominator;
        auto imag = (c1.imag() * c2.real() - c1.real() * c2.imag())
        / denominator;
        return {real, imag};
    }
    
    constexpr bool operator==(const Complex c1, const Complex c2) {
        return c1.real() == c2.real() && c1.imag() == c2.imag();
    }

    constexpr bool operator!=(const Complex c1, const Complex c2) {
        return !(c1 == c2);
    }

    inline bool operator<(const Complex c1, const Complex c2) {
        return c1.real() < c2.real() ||
          (c1.real() == c2.real() && c1.imag() < c2.imag());
    }

    // auto operator<=>(const Complex) = default;
}  // namespace complex_numbers

namespace complex_numbers::literals {
    constexpr Complex operator""_i(long double imag) {
        return {0, static_cast<double>(imag)};
    }

    constexpr Complex operator""_i(unsigned long long imag) {
        return {0, static_cast<double>(imag)};
    }
}
namespace std {
    template<>
    struct hash<complex_numbers::Complex> {
        static constexpr auto prime = []() -> std::size_t {
            if (std::numeric_limits<std::size_t>::digits == 32)
                return 4294967291U;
            if (std::numeric_limits<std::size_t>::digits == 64)
                return 18446744073709551557U;
            throw std::exception();
        }();
    std::size_t operator()(complex_numbers::Complex c) const {
        return hash<double>()(c.real()) * prime + hash<double>()(c.imag());
    }
};
}
#endif  // COMPLEX_NUMBERS_H
