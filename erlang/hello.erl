% http://egarson.blogspot.nl/2008/03/real-erlang-hello-world.html
-module(hello).

% 0 is number of arguments
-export([start_me/0]).


% "Pid" - reserved name?? no;
% the thing is, you should start
% with uppercase

% "spawn" returns process identifier
% The spawn invocation starts an Erlang process
% which wraps the loop() function just below it.
start_me() ->
   spawn(fun() -> loop() end).

loop() ->
    % The process waits (semantically at the receive statement)
    % for a message which matches one of its receive clauses.
   receive
      say_hello ->
         io:format("Hello, World!~n"),
         % tail-recursive call back to loop()
         loop();

      goodbye_now ->
         ok
   end.

   % Erlang is a single-assignment language. The benefits of this paradigm include
   % the ability for the compiler and runtime to make fancy optimizations,
   % and it also greatly eases debugging because variables are immutable.