function raindrops(number)
    raindrops = ""
    if number % 3 == 0
        raindrops = string(raindrops, "Pling")
    end
    if number % 5 == 0
        raindrops = string(raindrops, "Plang")
    end
    if number % 7 == 0
        raindrops = string(raindrops, "Plong")
    end
    if length(raindrops) == 0
        return string(number)
    end
    return raindrops
end
