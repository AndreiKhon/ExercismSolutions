main () {
    [[ $# -ne 2 ]] && echo "Usage: hamming.sh <string1> <string2>" && return 1
    [[ ${#1} -ne ${#2} ]] && echo "strands must be of equal length" && return 1

    local dna1=$1
    local dna2=$2
    local dna_errors=0

    for i in $(seq 0 ${#dna1})
    do
        [[ "${dna1:i:1}" != "${dna2:i:1}" ]] && ((dna_errors+=1))
    done

    echo ${dna_errors}

    return 0
}

main "$@"