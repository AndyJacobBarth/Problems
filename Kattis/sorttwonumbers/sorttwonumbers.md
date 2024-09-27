# [Sort Two Numbers](https://open.kattis.com/problems/sorttwonumbers)

This problem gives us two integers $a, b$ requiring them to be sorted in ascending order.

We can simply compare the two numbers. If $a < b$, we can output them in the order given. Otherwise we can output them in the order `b a`.

It should be noted that $a, b \leq 10^6$, so at least $32$-bit signed integers should be used, since

$\max 32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^6 > 3 \times 10^4 \approx \max 16 \textunderscore signed \textunderscore int \textunderscore max$

## Pseudo Code
```
INPUT a, b

IF a < b:
    PRINT a + " " + b
ELSE:
    PRINT b + " " + a
```

## Time Complexity
Since we have a fixed amount of input with one comparison and two values printed, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.