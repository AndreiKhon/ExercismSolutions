module MariosMarvellousLasagna exposing (remainingTimeInMinutes)

preparationTimeInMinutes: Int -> Int
preparationTimeInMinutes layers = 
    let
        oneLayerCookingTime = 2
    in 
        oneLayerCookingTime * layers

remainingTimeInMinutes: Int -> Int -> Int
remainingTimeInMinutes layers passedTime =
    let
        expectedMinutesInOven = 40
        layersCookingTime = preparationTimeInMinutes layers
    in
        expectedMinutesInOven + layersCookingTime - passedTime
        
