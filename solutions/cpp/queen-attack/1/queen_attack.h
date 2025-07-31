#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H
#include <utility>
#include <cstddef>
#include <stdexcept>

namespace queen_attack {
using position = typename std::pair<int, int>;
inline bool isInside8x8Board(position piece) {
    auto [x, y] = piece;
    return x >= 0 && x < 8 && y >= 0 && y < 8;        
}
class chess_board {
public:
chess_board(position white, position black): white_(white), black_(black) {
    if(!isInside8x8Board(white) || !isInside8x8Board(black))
        throw std::domain_error("");
    if(white == black)
        throw std::domain_error("");
}
bool can_attack() const {
    auto [xW, yW] = white_;
    auto [xB, yB] = black_;
    if(xW == xB)
        return true;
    if(yW == yB)
        return true;
    if(std::max(xW, xB) - std::min(xW, xB) == std::max(yW, yB) - std::min(yW, yB))
        return true;
    return false;
}
position white() const {
    return white_;
}
position black() const {
    return black_; 
}
private:
    position white_{};
    position black_{};
};
}  // namespace queen_attack

#endif // QUEEN_ATTACK_H