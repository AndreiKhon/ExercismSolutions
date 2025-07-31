#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include <string>
#include <string_view>
#include <cctype>
namespace atbash_cipher {
    inline unsigned char get_atbash_symbol(unsigned char lower_symbol) {
        auto current_alphabet_index = lower_symbol - 'a';
        return 25 - current_alphabet_index + 'a';       
    }
    inline std::string encode(std::string_view msg) {
        std::string encoded_msg{};
        size_t symbol_counter = 0;
        encoded_msg.reserve(msg.size() + msg.size() / 5 + 1);
        for(auto symbol: msg) {
            if(std::isalpha(symbol)) { 
                encoded_msg.push_back(get_atbash_symbol(std::tolower(symbol)));
                ++symbol_counter;
            }
            if(std::isdigit(symbol)) {
                encoded_msg.push_back(symbol);
                ++symbol_counter;
            }
            if(symbol_counter % 5 == 0 && !std::ispunct(symbol) && !std::isspace(symbol)) 
                encoded_msg.push_back(' ');
        }
        if(symbol_counter % 5 == 0)
            encoded_msg.resize(encoded_msg.size() - 1);
        return encoded_msg;
    }
    inline std::string decode(std::string_view encoded_msg) {
        std::string msg{};
        msg.reserve(encoded_msg.size());
        for(auto encoded_symbol: encoded_msg) {
            if(std::isalpha(encoded_symbol)) 
                msg.push_back(get_atbash_symbol(std::tolower(encoded_symbol)));
            if(std::isdigit(encoded_symbol))
                msg.push_back(encoded_symbol);
        }
        return msg;
    }
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H