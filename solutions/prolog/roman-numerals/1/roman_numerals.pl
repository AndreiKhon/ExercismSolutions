
convert(N, Numeral) :-
    Ones is N mod 10,
    Tens is N div 10 mod 10,
    Hundreds is N div 100 mod 10,
    Thousands is N div 1000 mod 10,
    ones(Ones, OnesNumeral),
    tens(Tens, TensNumeral),
    hundreds(Hundreds, HundredsNumeral),
    thousands(Thousands, ThousandsNumeral),
    string_concat(ThousandsNumeral, HundredsNumeral, ThousandsHundredsNumeral),
    string_concat(ThousandsHundredsNumeral, TensNumeral, ThousandsHundredsTensNumeral),
    string_concat(ThousandsHundredsTensNumeral, OnesNumeral, Numeral).
  
ones(0, "").
ones(1, "I").
ones(2, "II").
ones(3, "III").
ones(4, "IV").
ones(5, "V").
ones(6, "VI").
ones(7, "VII").
ones(8, "VIII").
ones(9, "IX").

tens(0, "").
tens(1, "X").
tens(2, "XX").
tens(3, "XXX").
tens(4, "XL").
tens(5, "L").
tens(6, "LX").
tens(7, "LXX").
tens(8, "LXXX").
tens(9, "XC").

hundreds(0, "").
hundreds(1, "C").
hundreds(2, "CC").
hundreds(3, "CCC").
hundreds(4, "CD").
hundreds(5, "D").
hundreds(6, "DC").
hundreds(7, "DCC").
hundreds(8, "DCCC").
hundreds(9, "CM").

thousands(0, "").
thousands(1, "M").
thousands(2, "MM").
thousands(3, "MMM").
