function CreateRaw(byte, rawLength, padding)
    local raw = string.rep(" ", padding)
    if byte == string.byte("A") then
        raw = raw .. string.char(byte)
    else
        local midPadding = rawLength - 2 * padding - 2
        raw = raw .. string.char(byte) .. string.rep(" ", midPadding) .. string.char(byte) 
    end
    raw  = raw .. string.rep(" ", padding) .. "\n"
    return raw
end
    
return function(which)
    local stringResult = ""
    local currCharacter = string.byte("A")
    local diamondCharacter = which:byte()
    local padding = diamondCharacter - currCharacter
    local rawLength = 2 * padding + 1
        
    while currCharacter <= diamondCharacter do
        stringResult = stringResult .. CreateRaw(currCharacter, rawLength, padding)
        padding = padding - 1
        currCharacter = currCharacter + 1
    end

    currCharacter = currCharacter - 2
    padding = padding + 2
    
    while currCharacter >= string.byte("A") do
        stringResult = stringResult .. CreateRaw(currCharacter, rawLength, padding)
        padding = padding + 1
        currCharacter = currCharacter - 1
    end
    return stringResult
end

