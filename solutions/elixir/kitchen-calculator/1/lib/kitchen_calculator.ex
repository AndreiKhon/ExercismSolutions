defmodule KitchenCalculator do
  def get_coeff(:milliliter), do: 1
  def get_coeff(:teaspoon), do: 5
  def get_coeff(:tablespoon), do: 15
  def get_coeff(:fluid_ounce), do: 30
  def get_coeff(:cup), do: 240
  def get_volume(volume_pair), do: elem(volume_pair, 1)
  def to_milliliter({unit, volume}), do: {:milliliter, volume * get_coeff(unit)}
  def from_milliliter({:milliliter, volume}, unit), do: {unit, volume / get_coeff(unit)}
  def convert(volume_pair, unit), do: from_milliliter(to_milliliter(volume_pair), unit)
end
