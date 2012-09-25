% it's like a class
-module(hello2).
% but modules cannot have variables!
% only functions can have them, but,
% once defined, they cannot be re-assigned:
% "that would imply that the function has a state, which itdoes not"

% bracket is a list - dynamic array
% Functions must be exported before they can be called from outside the module where they are defined.
-export([hello_world/0]).

% it's like a method
hello_world() -> io:fwrite("hello, world\n").

% stringsare really just lists of integers

% A tuple is like a list, except you generally don’tgrow or shrink it

middle(Arg) ->
{ _First, Second, _Third } = Arg,
Second.
% todo: ask why "syntax error before: '->'"

% tupes - used to store fixed number of items
% lists - used to store fixed number of items



% Built In Functions (BIFs)

%     date()
%     time()
%     length([1,2,3,4,5])
%     size({a,b,c})
%     atom_to_list(an_atom)
%     list_to_tuple([1,2,3,4])
%     integer_to_list(2234)
%     tuple_to_list({})