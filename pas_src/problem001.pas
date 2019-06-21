{ Project Euler Problem 1 Solution }
{ }
{ Problem statement: }
{ If we list all the natural numbers below 10 that are multiples }
{ of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. }
{ Find the sum of all the multiples of 3 or 5 below 1000. }
{ }
{ Solution description: }
{ This script compares a brute force algorithm with O(n) with a }
{ formula-based algorithm with O(1). Performance differences are }
{ best observed with input numbers > 1000000. }
{ }
{ Authors: Philipp Schuette, Daniel Schuette }
{ Date: 2018/09/24 }
{ License: MIT (see ../LICENSE.md) }
program Problem001;

uses Sysutils;

var Sum: Int64;
var i: integer;

procedure AddToSum(i: integer);
begin
    Sum += i;
end;

begin
    Sum := 0;

    for i := 1 to 999 do
    begin
        if (i mod 3 = 0) then
            AddToSum(i)
        else if (i mod 5 = 0) then
            AddToSum(i);
    end;
    WriteLn('Result: ' + Sum.ToString);
end.
