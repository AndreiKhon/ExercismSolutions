defmodule LogParser do
  def valid_line?(line), do: line =~ ~r/^\[DEBUG|INFO|WARNING|ERROR\]/

  def split_line(line), do: Regex.split(~r/<[~*=-]*?>/, line)

  def remove_artifacts(line), do: Regex.replace(~r/end-of-line\d+/i, line, "")

  def tag_with_user_name(line) do
    regex_result = Regex.run(~r/User\s+(\S+)/, line)
    case regex_result do
      [_ | user_name] -> "[USER] #{user_name} #{line}"
      nil -> line
    end
  end
end
