#include "matching_brackets.h"
#include <stack>
namespace matching_brackets {
    bool is_close_bracket(unsigned char);
    bool is_open_bracket(unsigned char);
    unsigned char get_close_bracket(unsigned char open_bracket);

    bool check(std::string_view brackets) {
        std::stack<unsigned char> st;
        for(auto ch: brackets) {
            if(is_open_bracket(ch))
                st.push(ch);
            if(is_close_bracket(ch)) {
                if(st.empty())
                    return false;
                auto last_open_bracket = st.top();
                if(get_close_bracket(last_open_bracket) == ch)
                    st.pop();
                else 
                    return false;
            }
        }
        return st.empty() ? true : false;
    }

    bool is_close_bracket(unsigned char ch) {
        switch(ch) {
            case ')': [[fallthrough]];
            case ']': [[fallthrough]];
            case '}': 
                return true;
            default:
                return false;
        }
        return false;
    }

    bool is_open_bracket(unsigned char ch) {
        switch(ch) {
            case '(': [[fallthrough]];
            case '[': [[fallthrough]];
            case '{': 
                return true;
            default:
                return false;
        }
        return false;
    }

    unsigned char get_close_bracket(unsigned char open_bracket) {
        switch(open_bracket) {
            case '(':
                return ')';
            case '[':
                return ']';
            case '{':
                return '}';
            default:
                return 0;
        }
    }
}  // namespace matching_brackets
