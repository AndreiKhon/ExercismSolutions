function largest_product(str, span)
    strLength = length(str)
    if span > strLength || strLength == 0 && span != 0
        throw(ArgumentError("Krya"))
    end
    max_product = 0
    if strLength == 0 || span == 0
        return 1
    end
    for i  = 1 : strLength - span + 1
        spanStr = str[i : i + span - 1]
        in('0', spanStr) && continue            
        value = parse(Int64, str[i : i + span - 1])
        product = calculate_product(value)
        if product > max_product            
            max_product = product
        end
    end
     return max_product
end


function parseInt64(str)
    value = 0
    for ch in str
        if ch >= '0' && ch <= '9'
            value *= 10
            value += ch - '0'
        else
            return 1
        end
    end
    return value
end

function calculate_product(value)
    if value == 0
        return 0
    end
    product = 1
    while value > 0
        @show value % 10
        product *= value % 10
        value ÷= 10
    end
@show product
    return product
end