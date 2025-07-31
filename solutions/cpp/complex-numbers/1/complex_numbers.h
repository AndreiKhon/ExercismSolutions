#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <cmath>

namespace complex_numbers {
class Complex {
    public:
        template <typename T>
        Complex(T real = 0, T imagine = 0) : 
            real_(real), imag_(imagine) { 
        }

        double real() const { 
            return real_; 
        } 

        double imag() const { 
            return imag_; 
        }

        Complex conj() const { 
            return {real_, -imag_}; 
        }

        Complex exp() const { 
            auto real = std::exp(real_) * std::cos(imag_);
            auto imag = std::exp(real_) * std::sin(imag_);
            return {real, imag};
        }

        double abs() const { 
            return std::sqrt(real_ * real_ + imag_ * imag_); 
        }

        Complex operator+(const Complex& complex) const { 
            auto real = real_ + complex.real();
            auto imag = imag_ + complex.imag();
            return {real, imag}; 
        }

        Complex operator-(const Complex& complex) const { 
            auto real = real_ - complex.real();
            auto imag = imag_ - complex.imag();
            return {real, imag}; 
        }

        Complex operator*(const Complex& complex) const { 
            auto real = real_ * complex.real() - imag_ * complex.imag();
            auto imag = imag_ * complex.real() + real_ * complex.imag();
            return {real, imag};
        }

        Complex operator/(const Complex& complex) const { 
            auto real = (real_ * complex.real() + imag_ * complex.imag()) 
                / (complex.real() * complex.real() + complex.imag() * complex.imag());
            auto imag = (imag_ * complex.real() - real_ * complex.imag())
                / (complex.real() * complex.real() + complex.imag() * complex.imag());
            return {real, imag};
        }

        bool operator==(const Complex& complex) const {
            return real_ == complex.real() && imag_ == complex.imag();
        }

private:
        double real_;
        double imag_;
    };
}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
