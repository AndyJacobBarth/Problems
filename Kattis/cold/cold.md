# [Cold](https://open.kattis.com/problems/cold)

In this problem, we are given $n$ followed by $n$ temperatures $t_1,...,t_n$. We must output how many temperatures are below $0$.

We can simply iterate through the input, and make an if conditional, where if $t < 0$, we increment some counter `total`. Since $n$ is only used to give us the number of following input, we can use it to increment through the rest of the input.

We could attempt to sort the data before analyzing, and when we reached $t_i > 0$, we would output `total` and terminate the program. In the worst case, all the values are negative, and sorting would have made the problem more complex $O(n \log n)$. In the best case, we find the first value is positive or $0$ after sorting and exit the program early. However, since we have to parse the temperatures into separate values and store them, we would still be interpreting the input at $O(n)$, so this is is not very practical.

We are told that $n \leq 100$, so sorting would be relatively quick. with $t \leq |10^6|$, we need to choose a data type that is at least a $32$-bit signed integer:

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31} - 1 > 2 \times 10^9 > 10^6 = \max t > 3 \times 10^4 \sim 2^{15}-1 = 16 \textunderscore signed \textunderscore int \textunderscore max$

## Pseudo Code
Comparing each input:
```
INPUT n
total = 0

WHILE n > 0:
    INPUT t
    IF t < 0:
        total++
    n--

PRINT total
```

## Time Complexity
Reading the input is $O(1)$ time for $n$ input, resulting in a total time of $O(n)$. Each input is compared while being interpreted, and all arithmetic and printing operations are $O(1)$ time. We can do no better since we must interpet all the input, so the total complexity is therefore $O(n) = \Omega(n) = \Theta(n)$.