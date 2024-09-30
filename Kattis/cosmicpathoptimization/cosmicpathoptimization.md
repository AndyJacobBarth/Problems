# [Cosmic Path Optimization](https://open.kattis.com/problems/cosmicpathoptimization)

This problem gives a value $M$ representing the following temperatures $T_1,...,T_M$ that are input on the next line, all in Kelvin. We want to print the mean temperature in Kelvin.

The mean is defined as follows:

$(\sum_{i=1}^M T_i) / M$

In our program, we can first use a for loop with some accumulator `sum` initialized to $0$  that adds all the temperatures input. We can then divide the result by $M$ to get the mean, or average.

We must use $M$ as part of our overall calculations, so we will iterate normally without manipulating $M$.

We are told that $T_i \leq 10^5$, so we should store the temperatures with a data type of at least $32$-bit signed integers, since

$\max 32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^5 > 3 \times 10^4 \approx 2^{15}-1 = \max 16 \textunderscore signed \textunderscore int \textunderscore max$

Since the temperature is all on one line, careful consideration should be made to interpret this input correctly. The pseudocode assumes the input can be handled individually, but programming languages like Python and Bash must transfer the data into a coherent data structure. Python can achieve this using `list()`, and within it, using `map(int, input().split())` which converts the input to `int`'s (without this conversion, this is simplified to `list(input.split())`). Bash requires the argument `-a` within `read` so it treats the input as an array that can then be iterated over.

## Pseudo Code
```
INPUT M
sum = 0

FOR i IN {1..M}:
    INPUT T

    sum += T

PRINT sum/M
```

## Time Complexity
We loop through $M = n$ temperatures, and can do no better. The operations within the loop take $O(1)$ time, so the overall time complexity is exactly $O(n) = \Omega(n) = \Theta(n)$.
