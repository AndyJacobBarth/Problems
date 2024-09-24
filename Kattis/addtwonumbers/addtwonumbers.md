# [Add Two Numbers](https://open.kattis.com/problems/addtwonumbers)

This problem simply asks us to sum two inputs $a, b$.

There's not anything to consider here. $a, b$ are positive integers. We can simply add $a + b$ and print the result.

We see in the problem that $a, b \leq 10^6$, so we need to make sure that we use a data type at least of $32$-bit signed integer because of the following:

$\max 32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^6 > 3 \times 10^4 \approx \max 16 \textunderscore signed \textunderscore int \textunderscore max$

## Pseudo Code
```
INPUT a, b

PRINT a + b
```

## Time Complexity
We are reading a fixed amount of input and printing a fixed amount of input with $O(1)$ arithmetic operations, resulting in an overall time complexity of exactly $O(1) = \Omega(1) = \Theta(1)$.