# [Dagatal](https://open.kattis.com/problems/dagatal)

This problem asks us to output the number of days in a given month of the year $m$. Given that we are basing this off $2019$, it is not a leap year, so February will have $28$ days.

This is a simple if statement, with three cases. Thereis one month, February, input as $2$. There are months of 31 days, which numerically are $1, 3, 5, 7, 8, 10, 12$. The remaining months are of length 30 days, which are $4, 6, 9, 11$. 

Without getting too complicated, we can just use an if/else if/else statement and compare these instances. Since we can hard code these values, this would also be the fastest way.

An interesting, but less efficient way, is to come up with a mathematical formula for either the sequence of 30 days or sequence of 31. Using the OEIS, we can check for the sequence and see if we can reverse a formula.  

For the sequence of 30 days, it's *almost* interesting that they are either $1$ or $4 \mod 5$, but obviously $1$ is also in this sequence, which is for 31 days. Any further results appear to not be practically reversible, or include digits we don't want to include.  

For the sequence of 31 days, it's revealed that they are part of the [Beatty sequence](https://en.wikipedia.org/wiki/Beatty_sequence) for $(3 + \sqrt{17})/4$, $\sqrt{\pi}$, and $e^\gamma$, where $\gamma$ is the [Euler-Mascheroni constant](https://en.wikipedia.org/wiki/Euler%27s_constant). It is proven that  a month $m$ belongs to one of these Beatty sequences iff $1 - \frac 1r < [ \frac mr ]$, where $[\frac mr]$ is the fractional part. With enough precision, we can compare whether the number $1 \leq m \leq 12$ obeys this condition. Using this is most certainly overkill and would only increase the number of operations, but it was fun to explore.

## Psuedo Code
Comparing each case:
```
INPUT m
IF m == 2:
    PRINT 28
ELSE IF m == {4, 6, 9, 11}:
    PRINT 30
ELSE
    PRINT 31
```
Using the ridiculous mathematical method:
```
INPUT m
# Below can be any of the above mentioned constants
r = sqrt(pi)
IF m == 2:
    PRINT 28
ELSE IF 1 - 1/r < FRAC(m/r):
    PRINT 31
ELSE
    PRINT 30
```

## Time Complexity
Since we are only doing at most two comparisons, this has time complexity of $O(1) = \Omega(1) = \Theta(1)$.