(ns log-levels
  (:require [clojure.string :as str]))

(defn message
  "Takes a string representing a log line
   and returns its message with whitespace trimmed."
  [s]
  (str/trim (first (rest (str/split s #"(: )|(\\[rtn])"))))
  )

(defn log-level
  "Takes a string representing a log line
   and returns its level in lower-case."
  [s]
  (def log-str (first (str/split s #"(: )")))
  (def log-str-len (count log-str))
  (str/lower-case (subs log-str 1 (- log-str-len 1)))
  )

(defn reformat
  "Takes a string representing a log line and formats it
   with the message first and the log level in parentheses."
  [s]
  (str (message s) " (" (log-level s) ")")
  )
