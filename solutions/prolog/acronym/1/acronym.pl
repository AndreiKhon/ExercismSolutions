
abbreviate(Sentence, Acromym) :-
	split_string(Sentence, ' -', ' ,-_', Words),    
    concat_first_letters(Words, AcronymLow),
    string_upper(AcronymLow, Acromym). 

concat_first_letters([H|T], ConcatedLetters) :-
    sub_string(H, 0, 1, _, FirstLetter),
    concat_first_letters(T, ConcatedLettersRec),
    string_concat(FirstLetter, ConcatedLettersRec, ConcatedLetters).

concat_first_letters([], "").