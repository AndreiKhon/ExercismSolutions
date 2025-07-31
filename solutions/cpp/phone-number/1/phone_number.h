#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H
#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <array>
#include <stdexcept>
namespace phone_number {
  constexpr size_t number_length = 10;
  class phone_number { 
    std::array<unsigned char, number_length> raw_number{};
  public:
    operator std::string() const {
        std::string formated_number{};
        formated_number += "(";
        formated_number += area_code();
        formated_number += ") ";
        formated_number += std::string(raw_number.begin() + 3, raw_number.begin() + 6);
        formated_number += "-";
        formated_number += std::string(raw_number.begin() + 6, raw_number.begin() + 10);
        return formated_number;
    }
    phone_number(std::string_view number) {
      size_t digits_counter = 0;
      for(auto symbol: number) {
        if(std::isdigit(symbol)) {
          if(!digits_counter && symbol == '1')
            continue;
          if(digits_counter >= number_length)
            throw std::domain_error("wrong digits count");
          raw_number[digits_counter] = symbol;
          ++digits_counter;
        }
      }
      if(digits_counter != 10)
        throw std::domain_error("wrong digits count");
      if(raw_number[0] < '2' || raw_number[3] < '2') {
        for(auto num: raw_number)
          std::cout << num;
        std::cout << std::endl;
        throw std::domain_error("wrong area/exchange code " + std::string(raw_number.begin(), raw_number.end()));
      }
    }
    std::string number() const {
      return std::string(raw_number.begin(), raw_number.end());
    }
    std::string area_code() const {
      return std::string(raw_number.begin(), raw_number.begin() + 3);
    }
  };
}  // namespace phone_number

#endif // PHONE_NUMBER_H
