unique([]).
unique([Head|Tail]) :- 
    not(member(Head, Tail)),
    unique(Tail).

is_alnum(Char) :-
    char_type(Char, alnum)

isogram(false).

isogram(Phrase) :-
    string_lower(Phrase, LowerCase),
    string_chars(LowerCase, ListChars),
    include(is_alnum, ListChars, ListAlnums),
    unique(ListAlnums).
    
