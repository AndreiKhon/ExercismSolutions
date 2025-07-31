(ns cars-assemble)



(defn production-rate
  "Returns the assembly line's production rate per hour,
   taking into account its success rate"
  [speed]
  (def min-car-production 221)
  (cond (= speed 0) 0.0
        (< speed 5) (* 1.0 speed min-car-production)
        (< speed 9) (* 0.9 speed min-car-production)
        (< speed 10) (* 0.8 speed min-car-production)
        (= speed 10) (* 0.77 speed min-car-production)
        :else 0)
  )

(defn working-items
  "Calculates how many working cars are produced per minute"
  [speed]
  (int (/ (production-rate speed) 60))
  )
