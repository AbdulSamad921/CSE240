%Homework6
%Abdul Samad Khan
% 2)fact and rule for 'weather is hot.if weather is hot,everyone likes
% it'
% 3) explanation of result of 2 prolog queries Translating english
% 4) statements in prolog Result of running prolog facts, rules and
% queries
% 5) answering result of prolog function
% 6) translating fib prolog to english, explaining fib step by
% step,answer of the given queries
% 7) translating english sentences to prolog
% 8) Prolog function for computing sum of n numbers

%Q2)...........
hot(weather).
likes(_,weather):-hot(weather).

%Q3)....................
% Yes they both produce the same result as in the first query the format
% is what we learned in LISP so
% prolog also follow the LISP form of operation hence -(+(5,6),4) will
% give 7
% and query 2 will also give 7 as N will get the value from (5+6)-4.

%Q4)...............
%facts
woman(jane).
man(john).
healthy(jane).
healthy(john).
wealthy(john).
%setting facts for woman,man,healthy,wealthy
%rules
traveller(X):-healthy(X),wealthy(X).
travel(X):-traveller(X).

%queries
%?- travel(X).
%?- healthy(X),wealthy(X).


%Q5)..................
vegetable(X).
%X=carrot
%X=egg_plant

vegetable(potato).
%false

likes(jose, What).
%What= carrot
%What= egg_plant

likes(Who, egg_plant).
%Who=jose

loves(Who, egg_plant).
%Who=jose
%Who=james

%Q6).......................
%fibonacci series of 1 is 0
fib(1,1).
%fibonacci series of 2 is 1
fib(2,1).
%fibonacci series of N is R if N>=3 and N1 is N-1 and N2 is N-2
%and fibonacci series of N1 is R1 and fibonacci series of N2 is R2 and
%R is sum of R1 R2.
fib(N,R):-
	N >= 3,
	N1 is N-1,
	N2 is N-2,
	fib(N1,R1),
	fib(N2,R2),
	R is R1+R2.
%b) first we will set rules for when N=1 and N=2,
%   then fib(N,R) is run here N=3 so in first step it would check if the number
%   is greater then 3 or not then N1 and N2 will be assigned where N1 is N-1 ane
%   N2 is N-2  then we again call fib(2,R1) and fib(1,R2), the return value R1 and R2 will be 1
%   by both fib then sum of R1 and R2 will be done and R will be the return value which in this case will be 2
%   which will be the answer

%c)fib(9,R) wil give the fibonacci sum of 9 that is 34 and if we press enter again
%fib(9,9) will give false as there is no fact declared as fib(9,9) in out dataset

%Q7).....................................
%a)
reads(john,programming_book).

%queries:
%?- reads(X,programming_book).
%?- reads(john,X).

%b)
%facts:
student(john,asu).
student(bill,asu).
student(jack,ua).
%rule:
likes(sparky,X):-student(X,asu).

%c)
%query for part b
%?- likes(sparky,Who).

%d)
%fact:
city(phoenix).
city(la).
city(tulsa).
big(phoenix).
big(la).
crowdie(phoenix).
crowdie(la).
%rules:
hates(janes,X):- big(X),crowdie(X).
%query:
%?- hates(janes,X).

%Q8).........................
sum(0,0).
%base case
sum(Y,X) :-
    Y > 0,
    Y1 is Y-1,
    sum(Y1,Z),
    X is Y + Z.
% function call, check if Y is greater then 0, decreament 1 in Y, make a
% new function call with new Y1 to sum, return the value X by adding the
% result of function call and the original Y




























