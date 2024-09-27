# [Sort Two Numbers](https://open.kattis.com/problems/sorttwonumbers)

This problem gives us two integers $a, b$ requiring them to be sorted in ascending order.

We can simply compare the two numbers. If $a < b$, we can output them in the order given. Otherwise we can output them in the order `b a`.

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