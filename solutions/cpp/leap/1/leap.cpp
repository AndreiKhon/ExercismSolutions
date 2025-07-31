#include "leap.h"

namespace leap {
    bool is_leap_year(size_t year) {
        if(year % 400 == 0)
            return true;
        if(year % 4 == 0 && year % 100 != 0)
            return true;
        return false;
    }
}  // namespace leap
