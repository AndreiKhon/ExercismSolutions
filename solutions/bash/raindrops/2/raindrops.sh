main () {
    (( $1 % 3 == 0 )) && printf "Pling"
    (( $1 % 5 == 0 )) && printf "Plang"
    (( $1 % 7 == 0 )) && printf "Plong"
    (( $1 % 3 )) && (( $1 % 5 )) && (( $1 % 7 )) && printf "%d" $1
    return 0
}

main "$@"