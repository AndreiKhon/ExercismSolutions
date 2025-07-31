function sum_of_multiples(limit, factors)
    set = Set(factor * multiply 
        for factor in factors 
            if factor > 0 
                for multiply in 1:floor(limit/factor) 
                    if factor * multiply < limit)
                        
    return reduce(+, set; init=0)
end
