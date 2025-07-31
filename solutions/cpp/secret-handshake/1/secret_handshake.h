#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H
#include <vector>
#include <string>
#include <cstddef>
namespace secret_handshake {
    inline std::vector<std::string> commands(size_t secret) {
        std::vector<std::string> handshake{};
        size_t reverse_bit = secret >> 4 & 1;
        size_t jump_bit = secret >> 3 & 1;
        size_t close_eyes_bit = secret >> 2 & 1;
        size_t doble_blink_bit = secret >> 1 & 1;
        size_t wink_bit = secret & 1;
        if(reverse_bit) {
            if(jump_bit)
                handshake.emplace_back("jump");
            if(close_eyes_bit)
                handshake.emplace_back("close your eyes");
            if(doble_blink_bit)
                handshake.emplace_back("double blink");
            if(wink_bit)
                handshake.emplace_back("wink");  
        }
        else {
            if(wink_bit)
                handshake.emplace_back("wink");
            if(doble_blink_bit)
                handshake.emplace_back("double blink");
            if(close_eyes_bit)
                handshake.emplace_back("close your eyes");
            if(jump_bit)
                handshake.emplace_back("jump");
        }
        return handshake;
    }
}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
