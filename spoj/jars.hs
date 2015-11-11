{-
JARJAR - Helping Jar Jar Binks

A job has been assigned to Jar Jar Binks, it goes as follows:

There are N spaceships parts, each with a weight of Wi kg. Given a weight W, he has to show 
how many parts can be used in order to make a ship with a weight of exactly W kg. He has to
show all possible solutions, of course if possible.

 
Input

There will be several cases, each beginning with two integers N, Q (1<=N<=60, 0<=Q<=10000).

Next there will be N positive integers representing the weights of the N spaceship parts (1<=Wi<=1000).

Q lines will follow, each one with only one (not necessarily positive) integer W, the total weight of the spaceship.

End of input will be denoted with N = 0 and Q = 0. This case should not be processed

 
Output

Print a line with K integers per query in ascending order. They must represent the amount of 
pieces that can be used to make a spaceship with weight W.

If there is no way to make a spaceship with weight W, output a line with the string 
“That's impossible!” (quotes to clarify)

 
Example

Input:

5 4

1 2 3 1 1

3

5 

1

9
0 0

Output:

1 2 3

2 3 4

1
That's impossible!


Explanation of the query W = 5

A spaceship with weight = 5 kg can be formed with 2, 3 and 4 parts, for example:
2 kg + 3 kg = 5 kg

3 kg + 1 kg + 1 kg = 5 kg
1 kg + 1 kg + 1 kg + 2 kg = 5 kg
-}



import Data.Map as Map


-- reduce 

main = do
        


