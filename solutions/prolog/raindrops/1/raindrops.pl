is_any_mod(N, [Head|Tail]) :-
    N mod Head =:= 0;
    is_any_mod(N, Tail).
is_any_mod(_, []) :-
    false.

convert(N, Sound) :-
    is_any_mod(N, [3,5,7]),
    pling(N, Raindrop3),
    plang(N, Raindrop5),
    plong(N, Raindrop7),
    string_concat(Raindrop3, Raindrop5, Raindrop35),
    string_concat(Raindrop35, Raindrop7, Sound).
convert(N, Sound) :-
    not(is_any_mod(N, [3,5,7])),
    number_string(N, Sound).

pling(N, "Pling") :-
    N mod 3 =:= 0.
pling(N, "") :-
    N mod 3 =\= 0.
plang(N, "Plang") :-
    N mod 5 =:= 0.
plang(N, "") :-
    N mod 5 =\= 0.
plong(N, "Plong") :-
    N mod 7 =:= 0.
plong(N, "") :-
    N mod 7 =\= 0.
