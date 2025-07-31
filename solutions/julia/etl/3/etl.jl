function transform(input::AbstractDict)
    return Dict{Char,Integer}(letter => points for (points, values) in input for letter in lowercase.(values))
end
