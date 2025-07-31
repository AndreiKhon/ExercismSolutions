defmodule BirdCount do
  def today([]), do: nil
  def today([head | _]), do: head
  def increment_day_count([]), do: [1]
  def increment_day_count([head | tail]), do: [head + 1 | tail]
  def has_day_without_birds?([]), do: false
  def has_day_without_birds?([head | tail]), do: head == 0 or has_day_without_birds?(tail)
  def total([]), do: 0
  def total([head | tail]), do: head + total(tail)
  def boolean_to_integer(true), do: 1
  def boolean_to_integer(false), do: 0
  def busy_days([]), do: 0
  def busy_days([head | tail]), do: boolean_to_integer(head >= 5) + busy_days(tail)
end
