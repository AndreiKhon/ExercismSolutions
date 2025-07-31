#include "word_count.h"
namespace word_count {

void remove_quots(std::string& str) {
    if(str.back() == '\'')
        str.erase(str.size() - 1, 1);
    if(str.front() == '\'')
        str.erase(0, 1);
}

std::map<std::string, int> words(std::string_view str) {
        std::string word{};
        std::map<std::string, int> words_map{};
        for(unsigned char ch: str) {
            ch = tolower(ch);
            if(isalnum(ch) || (ch == '\'')) {
                word.push_back(ch);
            }
            else {
                if(isspace(ch) || ispunct(ch)) {
                    if(!word.empty()) {
                        remove_quots(word);
                        words_map[word] += 1;
                        word.clear();
                    }
                }
            }
        }
        if(!word.empty()) {
            remove_quots(word);
            words_map[word] += 1;
        }
        return words_map;
}
}  // namespace word_count
