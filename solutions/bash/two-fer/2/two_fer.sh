main () {
    local placeholder=$1
    if [[ $# -eq 0 ]]; then
        local placeholder="you"
    fi
    echo "One for $placeholder, one for me."
    return 0
}

main "$@"