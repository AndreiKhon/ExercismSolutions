function transform(input::AbstractDict)
    return merge!(Dict{Char,Integer}(), Dict(letter => points for (points, values) in input for letter in lowercase.(values)))
end
