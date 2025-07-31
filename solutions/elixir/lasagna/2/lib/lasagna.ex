defmodule Lasagna do

  def expected_minutes_in_oven(), do: 40 

  def remaining_minutes_in_oven(spent_time), do: expected_minutes_in_oven() - spent_time

  def preparation_time_in_minutes(layer_count), do: 2 * layer_count

  def total_time_in_minutes(layer_count, spent_time), do: spent_time + preparation_time_in_minutes(layer_count)

  def alarm(), do: "Ding!"
end
