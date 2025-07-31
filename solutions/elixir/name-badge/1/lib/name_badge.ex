defmodule NameBadge do

  defp print_id(id) do
    if id do
      "[#{id}] - "
    else
      ""
    end
  end

  defp print_department(department) do
    if department do
      "#{String.upcase(department)}"
    else
      "OWNER"
    end
  end

  def print(id, name, department) do
    print_id(id) <>  "#{name} - " <> print_department(department)
  end
end
