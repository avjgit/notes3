-module(counter).
-export([start/0, codeswitch/1]).

start() -> loop(0).

loop(Sum) ->
    receive
        {increment, Count} ->
            loop(Sum + Count);
        {counter, Pid} ->
            Pid ! {counter, Sum},
            loop(Sum);
        code_switch ->
            % forces the use of 'codeswitch'
            % from latest version
            ?MODULE:codeswitch(Sum)
    end.

codeswitch(Sum) -> loop(Sum).