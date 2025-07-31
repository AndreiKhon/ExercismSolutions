
space_age(Planet, AgeSec, Years) :-
    Planet == "Earth",
    Years is AgeSec / 31557600.

space_age(Planet, AgeSec, Years) :-
    Planet == "Mercury",
    space_age("Earth", AgeSec / 0.2408467, Years).

space_age(Planet, AgeSec, Years) :-
    Planet == "Venus",
    space_age("Earth", AgeSec / 0.61519726, Years).

space_age(Planet, AgeSec, Years) :-
    Planet == "Mars",
    space_age("Earth", AgeSec / 1.8808158, Years).

space_age(Planet, AgeSec, Years) :-
    Planet == "Jupiter",
    space_age("Earth", AgeSec / 11.862615, Years).

space_age(Planet, AgeSec, Years) :-
    Planet == "Saturn",
    space_age("Earth", AgeSec / 29.447498, Years).

space_age(Planet, AgeSec, Years) :-
    Planet == "Uranus",
    space_age("Earth", AgeSec / 84.016846, Years).

space_age(Planet, AgeSec, Years) :-
    Planet == "Neptune",
    space_age("Earth", AgeSec / 164.79132, Years).


