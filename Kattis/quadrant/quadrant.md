# [Quadrant](https://open.kattis.com/problems/quadrant)

This problem wants us to take two input ($x, y$) and determine what quadrant on a Cartesian coordinate system they reside on.

There are four quadrants, with $(+x, +y)$ in the first quadrant. $(-x, +y)$ is in the second, $(-x, -y)$ is in the third, and $(+x, -y)$ is in the fourth. We need only to check the sign of the $x, y$ values to determine their placement. We will use a divide-and-conquer approach to solve this, although checking $x$ and $y$ in each if/else statement would at worst case lead to one more comparison than the approach provided below.

The integers are specified to never be $0$ and $|x|, |y| \leq 1000$, so the integers need only be at least 16-bit signed integers ($2^{15} - 1 > 3 \times 10^4 > 10^3$).

## Psuedo Code
```
INPUT x, y
IF x > 0:
    IF y > 0:
        PRINT 1
    ELSE
        PRINT 4
ELSE
    IF y > 0:
        PRINT 2
    ELSE
        PRINT 3
```

## Time Complexity
Because we only have to do at most $2$ comparisons, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.