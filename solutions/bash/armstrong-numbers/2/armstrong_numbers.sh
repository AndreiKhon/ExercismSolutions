main () {
    [[ $1 -eq 0 ]] && echo "true" && return 0
    local number=$1
    local number_length=$(echo "l(${number})/l(10)+1" | bc -l)
    number_length=${number_length%.*}
    local armstrong_sum=0
    while [[ $number -ne 0 ]]; do
        armstrong_sum=$(( armstrong_sum + (number % 10) ** number_length ))
        number=$(( number / 10 ))
    done
    [[ $1 -eq $armstrong_sum ]] && echo "true" && return 0
    echo "false"; return 0
}
main "$@"