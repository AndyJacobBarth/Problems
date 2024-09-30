# [Bitte ein Bit](https://open.kattis.com/problems/bitteeinbit)

This problem gives us $n$ bits, and asks that we output a random bit within the string.

Optimally, we can treat the bits as a string and output the first char. If the programming language permits, we can just read the first char, and not worry about any of the others.

Since $n \leq 100$, there is nothing major to analyze here. Even if $n$ was much larger, the problem can be done by just extracting the first char.

## Pseudo Code
```
INPUT n

PRINT n[0]
```

## Time Complexity
Retrieving and outputting the first char of a string is $O(1)$, so this executes in exactly $O(1) = \Omega(1) = \Theta(1)$ time.