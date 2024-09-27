# [Tri Area](https://open.kattis.com/problems/triarea)

In this problem, we are given two numbers $b$ and $h$ representing the base and height of a triangle, respectively. We must output the triangle's area.

The formula for the area of a triangle is the following:

$A = \frac 12 b h$

We can multiply by $0.5$ with $b$ and $h$ in our program and output the result.

The problem states that the relative error must be no more than $10^{-7}$, however it is also specified that $b, h$ are integers. The only values we can get are therefore multiples of $0.5$, and we only have to account for rounding error of $10^{-1}$. Also, $b, h \leq 10^4$, so we can use as little as $16$-bit signed integers ($10^4 < 3 \times 10^4 \approx 2^{15}-1 = \max 16 \textunderscore signed \textunderscore int \textunderscore max$).

## Pseudo Code
```
INPUT b, h

PRINT 0.5*b*h
```

## Time Complexity
Since we are taking a fixed amount of output and printing the product, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.