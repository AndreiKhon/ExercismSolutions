#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <cstddef>
namespace protein_translation {
    inline std::unordered_map<std::string_view, std::string_view> protein_map {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"},
        {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"}, 
        {"UGU", "Cysteine"}, {"UGC", "Cysteine"}, 
        {"UGG", "Tryptophan"}, 
        {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}, 
    };
    inline std::vector<std::string> proteins(std::string_view rna) {
        std::vector<std::string> proteins_{};
        for(size_t i = 0; i < rna.size() / 3; ++i) {
            std::string_view codon{rna.begin() + i * 3, 3};
            auto protein = protein_map[codon];
            if(protein == "STOP")
                break;
            proteins_.push_back(std::string(protein));
        }
        return proteins_;
    }
}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
