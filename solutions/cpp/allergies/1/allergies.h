#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <cstddef>
#include <array>
#include <string>
#include <unordered_set>
#include <algorithm>

namespace allergies {
   class allergy_test {
      size_t score;
      const std::array<std::string, 8> allergies {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
   public:
      bool is_allergic_to(std::string_view allergen) const {
          auto it = std::find(allergies.cbegin(), allergies.cend(), allergen);
          if(it != allergies.end()) {
              auto i = std::distance(allergies.cbegin(), it);
              if(score & 1 << i)
                  return true;
          }
          return false;
      }
      std::unordered_set<std::string> get_allergies() const {
          std:: unordered_set<std::string> current_allergies{};
          for(size_t i = 0; i < allergies.size(); ++i) {
             if(score & 1 << i)
                 current_allergies.insert(allergies[i]);
          }
          return current_allergies;
      }
      allergy_test(size_t score) : score(score) {}
   };
}  // namespace allergies

#endif // ALLERGIES_H