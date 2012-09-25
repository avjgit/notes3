-module(mathStuff).
-export([factorial/1, area/1]).

factorial(1) -> 1;
% factorial(N) -> N * factorial(N-1).
% now with GUARD! better (can be reordered)
factorial(N) when N > 0 -> N * factorial(N-1).

% Examples of Guards

%     number(X)   - X is a number
%     integer(X)  - X is an integer
%     float(X)    - X is a float
%     atom(X)     - X is an atom
%     tuple(X)    - X is a tuple
%     list(X)     - X is a list

%     length(X) == 3  - X is a list of length 3
%     size(X) == 2    - X is a tuple of size 2.

%     X > Y + Z   - X is > Y + Z
%     X == Y      - X is equal to Y
%     X =:= Y     - X is exactly equal to Y
%                       (i.e. 1 == 1.0 succeeds but
%                1 =:= 1.0 fails)

% square is atom, Side is variable
area({square, Side}) ->
    Side * Side;
area({circle, Radius}) ->
    3.14 * Radius * Radius;
area({triangle, A, B, C}) ->
    S = (A + B + C)/2,
    math:sqrt(S * (S-A) * (S-B) * (S-C));
area(Other) ->
    {invalid_object, Other}.