-module(reclists2).
-export([my_average/1]).

my_average(X) -> my_average(X, 0, 0).

my_average([H|T], Length, Sum) ->
    my_average(T, Length+1, Sum + H);
my_average([], Length, Sum) ->
    Sum / Length.
%this shit works)