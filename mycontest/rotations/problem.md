## Playing with strings

Hasmukh likes string computations and also he is good at it. One day, one of his friends comes to him with one such problem.

The problem is: Given a string S containing only alphabets, he has to rotate the string multiple times. Among the rotations, there are L left rotations and R right rotations.

The rotations are defined as follows:<br>
1.Each left rotation displaces all the characters leftward by one position and the first element goes to the last position.<br>
2.Each right rotation displaces all the characters rightward by one position and the last element comes to the first position.

Once the rotations are done, his friend gives Q number of queries. For each query q, Hasmukh has to answer the character at that position in the rotated string.

Hasmukh, feeling drowsy at the moment, wants you to answer him in his stead.

### Input
First line contains T - the number test cases.<br>
Each test case starts with a line containing four numbers - S, L, R and Q.<br>
The next Q lines each contain a query.

### Output
Output contains q lines, each displaying the character at the queried position.

### Time Limit
`2.00000 sec`

### Constraints
```
0 <= T <= 10^3
0 < |S| <= 10^3
0 <= L,R <= 10^3
0 <= Q <= 10^3
0 <= q < |S|

(|S| = size of the input string; consider 0 as the starting position of the string)
```

### Example 

Input:
```
1
abcdefghi 4 2 4
2
4
6
8
```

Output:
```
e
g
i
b
```

#### Explanation:

Input string:	abcdefghi <br>
The string after rotations:	cdefghiab <br>
e,g,i,b are the chars at the queried positions 2,4,6,8 respectively.



<p style="color:#2B3856">
Author: Sravan Kumar <br>
</p>

