#if !defined(GIGASECOND_H)
#define GIGASECOND_H
#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {
using namespace boost::posix_time;
    inline ptime advance(const ptime& time_from) {
        return time_from + seconds(1000000000);
    }
}  // namespace gigasecond

#endif // GIGASECOND_H