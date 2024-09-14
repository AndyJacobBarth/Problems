# [Which is Greater](https://open.kattis.com/problems/whichisgreater)

In this problem, we are simply comparing two inputs $a,b$, returning $1$ if $a > b$ and $0$ otherwise. We can use an if conditional.

The problem notes that $0 < a,b \leq 10^9$. This means we are not concerned for negative numbers, but we should ensure that we accept input taking at least data type of 32-bit signed int ($2^{31}-1 > 2 \times 10^9 > 10^9$).
## Pseudo Code
```
INPUT a, b

IF a > b:
    PRINT 1
ELSE
    PRINT 0

```

## Time Complexity
Because we are only doing one comparison, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.