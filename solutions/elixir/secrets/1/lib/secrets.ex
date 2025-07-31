defmodule Secrets do
  def secret_add(secret) do    
    secret_add = fn num ->
      num + secret
    end
  end

  def secret_subtract(secret) do
    secret_substract = fn num ->
      num - secret
    end
  end

  def secret_multiply(secret) do
    secret_multiply = fn num ->
      num * secret
    end
  end

  def secret_divide(secret) do
    secret_divide = fn num ->
      div(num, secret)
    end
  end

  def secret_and(secret) do
    secret_and = fn num ->
      Bitwise.band(secret, num)
    end
  end

  def secret_xor(secret) do
    secret_xor = fn num ->
      Bitwise.bxor(secret, num)
    end
  end

  def secret_combine(secret_function1, secret_function2) do
    secret_combine = fn num ->
      secret_function2.(secret_function1.(num))
    end
  end
end
