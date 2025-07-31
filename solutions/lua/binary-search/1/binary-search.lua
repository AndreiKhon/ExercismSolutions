return function(array, target)
    local left = 1
    local right = #array
    if left > right then
        return -1
    end
    local mid = left + (right - left) // 2
    repeat
        if array[mid] == target then
            return mid
        end
        if array[mid] > target then
            right = mid - 1
        end
        if array[mid] < target then
            left = mid + 1
        end
        mid = left + (right - left) // 2
        until left > right
    return -1
end
