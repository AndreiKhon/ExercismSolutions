local Hamming = {}

function Hamming.compute(a,b)
    if(#a ~= #b) then    
        return -1
    end
    
    local diffCount = 0
    for i = 1, #a do
        local va = string.byte(a, i)
        local vb = string.byte(b, i)
        if(va ~= vb) then
            diffCount = diffCount + 1
        end
    end
    return diffCount
end

return Hamming
