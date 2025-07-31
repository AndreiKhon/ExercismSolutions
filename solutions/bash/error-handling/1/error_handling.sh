main () {
    [[ $# -ne 1 ]] && echo "Usage: error_handling.sh <person>" && return 1
    echo "Hello, $1"
}

main "$@"