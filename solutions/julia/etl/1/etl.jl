function transform(input::AbstractDict)
    shinyDict = Dict{Char,Integer}()
    for points in keys(input)
        for letter in input[points]
            merge!(shinyDict, Dict(lowercase(letter) => points))
        end
    end
    return shinyDict
end

