(ns leap)

(defn leap-year? [year] 
  (if (or (zero? (mod year 400)) (and (zero? (mod year 4)) (not (zero? (mod year 100))))) true false)
)
