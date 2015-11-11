
__author__ = 'Divyanshu Kakwani'
__license__ = 'WTFPL'


t = int(input())

# The following code uses the following two properties:
# 1. All the external angles must sum to 360.
# 2. Following the regular-ness of a polygon, all of its external angles must be equal.
# => n * ext_angle = 360
# See https://www.mathsisfun.com/geometry/regular-polygons.html

for case in range(t):
    interior_angle = int(input())
    exterior_angle = 180 - interior_angle
    print ('YES' if (0 < exterior_angle < 180) and (360 % exterior_angle == 0)
                 else 'NO')

