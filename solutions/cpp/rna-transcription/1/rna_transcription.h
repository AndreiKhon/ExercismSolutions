#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H
#include <string>
namespace rna_transcription {
    inline char to_rna(char dna) {
        switch(dna) {
            case 'C':
                return 'G';
            case 'G':
                return 'C';
            case 'A':
                return 'U';
            case 'T':
                return 'A';
        }
        return 0;
    }
    inline std::string to_rna(std::string dna) {
        std::string rna;
        rna.reserve(dna.size());
        for(auto nucleotide: dna)
            rna.push_back(to_rna(nucleotide));
        return rna; 
    }
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H