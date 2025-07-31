local Hamming = {}

function Hamming.compute(a,b)
    if #a ~= #b then    
        return -1
    end
    
    local diffCount = 0
    for i = 1, #a do
        if a:byte(i) ~= b:byte(i) then
            diffCount = diffCount + 1
        end
    end
    return diffCount
end

return Hamming
