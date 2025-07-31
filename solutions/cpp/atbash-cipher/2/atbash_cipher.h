#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include <string>
#include <string_view>
#include <cctype>
namespace atbash_cipher {
    inline unsigned char get_atbash_symbol(unsigned char symbol) {
        return 'a' + 'z' - std::tolower(symbol);       
    }
    inline std::string encode(std::string_view msg) {
        std::string encoded_msg{};
        encoded_msg.reserve(msg.size() + msg.size() / 5 + 1);
        for(auto symbol: msg) {
            if(std::isalnum(symbol)) {
                if(encoded_msg.length() % 6 == 5) 
                    encoded_msg += ' ';
                if(std::isalpha(symbol)) 
                    encoded_msg += get_atbash_symbol(symbol);
                if(std::isdigit(symbol)) 
                    encoded_msg += symbol;
            }
        }
        return encoded_msg;
    }
    inline std::string decode(std::string_view encoded_msg) {
        std::string msg{};
        msg.reserve(encoded_msg.size());
        for(auto encoded_symbol: encoded_msg) {
            if(std::isalpha(encoded_symbol)) 
                msg += get_atbash_symbol(std::tolower(encoded_symbol));
            if(std::isdigit(encoded_symbol))
                msg += encoded_symbol;
        }
        return msg;
    }
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H