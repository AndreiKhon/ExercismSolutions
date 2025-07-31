#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <map>
#include <string_view>
#include <stdexcept>
namespace nucleotide_count {
    constexpr std::string_view nucleotides{"ATGC"};
    class counter {
        mutable std::map<char, int> nucleotides_map{{'A', 0}, {'T', 0}, {'G', 0}, {'C', 0}};
    public:
        counter(std::string_view dna) {
            for(auto nucleotide: dna) {
                if(nucleotides.find(nucleotide) == std::string_view::npos)
                    throw std::invalid_argument("");
                nucleotides_map[nucleotide] += 1;
            }
        }
        std::map<char, int> nucleotide_counts() const {
            return nucleotides_map;
        }
        size_t count(char nucleotide) const {
            if(nucleotides.find(nucleotide) == std::string_view::npos)
                    throw std::invalid_argument("");
            return nucleotides_map[nucleotide];
        }
        
    };
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H