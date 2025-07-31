defmodule HighSchoolSweetheart do
  def first_letter(name), do: String.trim(name) |> String.first()
  def initial(name), do: first_letter(name) |> String.upcase() |> Kernel.<>(".")

  def initials(full_name) do
    names = String.split(full_name)
    initial(List.first(names)) <> " " <> initial(List.last(names))
  end

  def pair(full_name1, full_name2) do
    """
         ******       ******
       **      **   **      **
     **         ** **         **
    **            *            **
    **                         **
    **     #{initials(full_name1)}  +  #{initials(full_name2)}     **
     **                       **
       **                   **
         **               **
           **           **
             **       **
               **   **
                 ***
                  *
    """
  end
end
