# [FYI](https://open.kattis.com/problems/fyi)

This problem gives us a $7$-digit telephone number $n$ and asks us to output `1` if the telephone number starts with `555` or print `0` otherwise. The significance of `555` stems from this being the directory information operator's prefix.

We can treat the telephone number as a string, and read the first three chars. If they are all $5$'s, we can print `1` and otherwise print `0`.

While the problem illustrates $n \sim 10^6$, we are not treating $n$ as an integer and don't have to worry about this constraint.

## Pseudo Code
```
INPUT n

IF n[0] == 5 AND n[1] == 5 AND n[2] == 5:
    PRINT 1
ELSE:
    PRINT 0
```

## Time Complexity
Since we are using a conditional on a single input, this is exactly time complexity of $O(1) = \Omega(1) = \Theta(1)$.