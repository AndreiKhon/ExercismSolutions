#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <cmath>
#include <cstdint>
#include <functional>
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
        return c1.abs() < c2.abs(); 
    }

    constexpr Complex operator""_i(long double imag) {
        return {0, static_cast<double>(imag)};
    }

    // auto operator<=>(const Complex) = default;
}  // namespace complex_numbers

namespace std {
    template<>
    struct hash<complex_numbers::Complex> {
       std::size_t operator()(const complex_numbers::Complex &c) const {
           auto real = static_cast<uint64_t>(c.real());
           auto imag = static_cast<uint64_t>(c.imag());
          return hash<uint64_t>()(real) ^ hash<uint64_t>()(imag); 
        }
    };
}
#endif  // COMPLEX_NUMBERS_H
