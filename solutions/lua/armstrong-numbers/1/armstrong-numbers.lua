local ArmstrongNumbers = {}

function ArmstrongNumbers.is_armstrong_number(number)
    local tmp = number
    local armstrongSum = 0
    local power = math.log10(number) // 1 + 1
    while tmp > 0 do
        local digit = tmp % 10
        armstrongSum = armstrongSum + (digit ^ power)
        tmp = tmp // 10
    end
    return (armstrongSum == number)
end

return ArmstrongNumbers
