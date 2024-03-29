
### Problem

Hasmukh is celebrating his 20th birthday in his hometown Jhalor. To make his birthday party grand,
he has decided to invite all the people of Jhalor to his party.

The city Jhalor consists of N houses interconnected by exactly N-1 roads in such a way that any house can be reached
by any other. One of these houses is owned by Hasmukh from where he sends out
his servants, one to each house of the city, to distribute the invitation cards. 

As commanded by Hasmukh, each servant goes directly to his assigned house as quickly as he can, drops the invitation instantly, and then returns to Hasmukh's house, again as quickly as he can.

Hasmukh is tight on time. So he wants you to tell him how long would it take for all of his
servants to return home so that he can give them further errands.

### Input

The first line contains the number of test cases T. Each test case starts with a line containing
N, the number of vertices, and H, the location of Hasmukh's house. This is followed by N-1 lines each 
containing three numbers - u, v, D - where u and v are the two ends of a road and D is the transit time(in mins)
through this road.

Note that the houses are numbered from 0 to N-1.

### Output

For each test case, print the time taken, in mins, for all the servants to return home.

### Constraints
```
0 < T <= 100
0 < N <= 1000
0 < H < N
0 < u, v < N
0 < D <= 10^9
```

### Time Limit
`1.0000 seconds`

### Example

Input
```
1
3 0
0 1 4
0 2 5
```

Output
```
10
```
Explanation

All the servants start at house 0. Following Hasmukh's command, one of the servants goes to
the house numbered 1 and another to the house numbered 2. The first one returns in 8 mins,
4 to reach house 1 and 4 to return, and the second returns in 10 mins. Hence, the answer is 10.


<p style="color:#2B3856">
Author: Divyanshu Kakwani <br>
</p>
