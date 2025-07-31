#include "raindrops.h"

namespace raindrops {
    std::string convert(size_t num) {
        if(num % 3 && num % 5 && num % 7)
            return std::to_string(num);
        std::string raindrop;
        if(num % 3 == 0)
            raindrop += "Pling";
        if(num % 5 == 0)
            raindrop += "Plang";
        if(num % 7 == 0) 
            raindrop += "Plong";
        return raindrop;
    }
}  // namespace raindrops
