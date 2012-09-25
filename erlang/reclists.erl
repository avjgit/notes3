-module(reclists).
-export([my_average/1]).

my_average(X) -> sum_them(X) / count_them(X).

sum_them([H|T]) -> H + sum_them(T);
sum_them([]) -> 0.

count_them([H|T]) -> H + count_them(T);
count_them([]) -> 0.

% todo: ask why this doesn't work?

