#if !defined(BEER_SONG_H)
#define BEER_SONG_H
#include <string>
namespace beer_song {
inline std::string verse(int n) {
    if(n == 2)
        return "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n";
    if(n == 1)
        return "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n";
    if(n == 0)
        return "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n"; 
    static std::string bottle_of_bear{" bottles of beer"};
    static std::string on_the_wall{" on the wall"};
    std::string verse_{};
    if(n > 2) {
        verse_ += std::to_string(n);
        verse_ += bottle_of_bear + on_the_wall + ", ";
        verse_ += std::to_string(n);
        verse_ +=  bottle_of_bear + ".\n" + "Take one down and pass it around, ";
        if(n - 1)
            verse_ += std::to_string(n - 1);
        else
            verse_ += "no more";
        verse_ += bottle_of_bear + on_the_wall + ".\n";
    }
   
    return verse_;
}
inline std::string sing(int n, int until = 0) {
    std::string sing_{};
    for(int i{n}; i > until; --i) {
        sing_ += verse(i) + "\n";
    }
    sing_ += verse(until);
    return sing_;
}
}  // namespace beer_song

#endif // BEER_SONG_H