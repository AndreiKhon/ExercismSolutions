#include "darts.h"
#include <cmath>
namespace darts {



unsigned int score(float x, float y) {
    auto radius = std::sqrt(x * x + y * y);
    if(radius <= 1.f)
        return 10;
    if(radius <= 5.f)
        return 5;
    if(radius <= 10.f)
        return 1;
    return {};
}

} // namespace darts