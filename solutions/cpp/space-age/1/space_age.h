#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

#include <ratio>
#include <cstddef>

namespace space_age {
    using mercury_year = std::ratio<2408467, 10000000>;
    using venus_year = std::ratio<61519726, 100000000>;
    using mars_year = std::ratio<18808158, 10000000>;
    using jupiter_year = std::ratio<11862615, 1000000>;
    using saturn_year = std::ratio<29447498, 1000000>;
    using uranus_year = std::ratio<84016846, 1000000>;
    using neptune_year = std::ratio<16479132, 100000>;

    class space_age {
        size_t earth_age_seconds;
    public:
        space_age(size_t earth_age_seconds) : earth_age_seconds(earth_age_seconds) {
            
        }
        inline double seconds() const {
            return earth_age_seconds;
        }
        inline double on_earth() const {
            return earth_age_seconds / 31557600.0;
        }
        inline double on_mercury() const {
            return on_earth() / mercury_year().num * mercury_year().den;
        }
        inline double on_venus() const {
            return on_earth() / venus_year().num * venus_year().den;
        }
        inline double on_mars() const {
            return on_earth() / mars_year().num * mars_year().den;
        }
        inline double on_jupiter() const {
            return on_earth() / jupiter_year().num * jupiter_year().den;
        }
        inline double on_saturn() const {
            return on_earth() / saturn_year().num * saturn_year().den;
        }
        inline double on_uranus() const {
            return on_earth() / uranus_year().num * uranus_year().den;
        }
        inline double on_neptune() const {
            return on_earth() / neptune_year().num * neptune_year().den;
        }
    };
}  // namespace space_age

#endif // SPACE_AGE_H