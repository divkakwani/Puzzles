## Problem

A surveyor is given a contract to survey a land for a construction. The construction is planned
in such a way that it should be in a regular shape. Given the angle between two sides of a construction shape X degrees, the surveyor needs to find whether he can survey a regular shaped land having an internal angle of X. As the surveyor has a heavy work load, your job is to help him by writing a simple program that prints YES if the construction is possible and NO if not.

### INPUT:
The first line contains the number of test cases T.
Each of the next T lines contains an integer x, the internal angle between the sides of the construction shape.

### OUTPUT:
T lines, each printing YES if the construction is possible or NO if not.

### Constraints:
```
0 <= T <= 10^5
0 <= X <= 10^9
```

### Time Limt:
```
1.000000 sec
```

### Sample test case:
Input:
```
2
60
70
```
Output:
```
YES
NO
```

### Explaination:
For the first test case X = 60 degrees. Since there exists a regular shape with 3 sides(a triangle), the construction is possible.

For the second test case X = 70 degrees. No construction is possible since there doesn't exist a regular-shape with the given internal angle.


<p style="color:#2B3856">
Author: Sravan Kumar <br>
</p>

