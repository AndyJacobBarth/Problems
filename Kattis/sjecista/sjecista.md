# [Sjecista](https://open.kattis.com/problems/sjecista)

For a given convex polygon of $N$ vertices, we need to output the number of intersections that occur. The problem stresses that there are no points where there is more than one intersection occurring.

The problem strongly hints that there is a known formula for such a property, so we shouldn't waste our time trying to exhaust a brute-force method for a solution. In fact, there is a formula for this:

$\frac {N(N-1)(N-2)(N-3)}{24}$

Deducing this formula actually involves some combinatorics and graph theory. I will leave it as an exercise for the reader to deduce this.

In our program, we can directly implement the arithmetic for this and output the solution.

The problem states that $3 \leq N \leq 100$, so we don't need to seriously consider any limitations here. Even for $N = 3$, the formula will hold true, since $N - 3 = 0$ for $N = 3$.

## Pseudo Code
```
INPUT N

PRINT N*(N - 1)*(N - 2)*(N - 3) / 24
```

## Time Complexity
We are doing a fixed number of arithmetic operations on $N$, so the overall complexity is $O(1) = \Omega(1) = \Theta(1)$.