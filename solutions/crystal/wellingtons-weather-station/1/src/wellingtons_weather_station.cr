class Temperature
  KELVINS_DIFF = 273.15
  def to_kelvin(celsius)
    celsius + KELVINS_DIFF
  end

  def round(celsius)
    celsius.round(1)
  end

  def to_fahrenheit(celsius)
    (celsius * 1.8 + 32).to_i
  end

  MIN_SENSORS = 4
  def number_missing_sensors(number_of_sensors)
    (MIN_SENSORS - number_of_sensors % MIN_SENSORS) % MIN_SENSORS
  end
end
