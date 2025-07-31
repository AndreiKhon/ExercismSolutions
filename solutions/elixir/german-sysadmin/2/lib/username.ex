defmodule Username do
  defguardp lowercase?(letter) when letter >= ?a and letter <= ?z  or letter == ?_
  defguardp german?(letter) when letter == ?ä or letter == ?ö or letter == ?ü or letter == ?ß

  defp german_to_latin(letter) do
    case letter do
      ?ä -> 'ae'
      ?ö -> 'oe'
      ?ü -> 'ue'
      ?ß -> 'ss'
      _ -> [letter]
    end
  end

  def sanitize([]), do: []
  def sanitize([first_letter | rest_letters]) do
    case first_letter do
      first_letter when lowercase?(first_letter) or german?(first_letter) -> german_to_latin(first_letter) ++ sanitize(rest_letters)
      _ -> sanitize(rest_letters)
    end
  end
end
