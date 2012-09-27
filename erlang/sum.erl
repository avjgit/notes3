-module(sum).
-export([sum_recursive/1, sum_tailrecursive/1]).

sum_recursive([H|T]) ->
    H + sum_recursive(T);
sum_recursive([]) ->
    0.

sum_tailrecursive([X]) ->
    sum_tailrecursive(X, 0).

sum_tailrecursive([H|T], Accumulator) ->
    sum_tailrecursive(T, H + Accumulator);
sum_tailrecursive([], Acc) ->
    Acc.

% why tailrecursive doesn't work?