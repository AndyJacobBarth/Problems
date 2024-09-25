# [Is it Halloween](https://open.kattis.com/problems/isithalloween)

This problem gives us various dates as input and asks us to output `yup` if it's Halloween (`OCT 31`) or `nope` otherwise. The formatting of dates are three letters followed by the day of the month as a digit, as written. There is actually one other date we should say `yup` to - `DEC 25`. The only reasoning behind this according to the problem is that $31_8 = 25_{10}$, which is not really a reason. It's clear this is a sly way of reasoning the idea of Halloween on Christmas day, made popular by the film "The Nightmare Before Christmas".

Our program needs to check whether the input is exactly `OCT 31` or `DEC 25`. If so, output `yup`, otherwise `nope`.

There are no serious edge cases to consider. We can treat the integers effectively as part of the string since we don't have to do any computations with them.

## Pseudo Code
```
INPUT date

IF date == "OCT 31 OR date == "DEC 25":
    PRINT "yup"
ELSE:
    PRINT "nope"
```

## Time Complexity
There are no loops and all conditionals and I/O take $O(1)$ time, so this problem takes exactly $O(1) = \Omega(1) = \Theta(1)$ time complexity.