# [Fimmtudagstilbod](https://open.kattis.com/problems/fimmtudagstilbod)

This problem is about the price of pizza as it linearly increases in price per year. We are given a specific year $y$ and must determine the price of pizza that year. We are told the original price in $2020$ was $1000$ ISK, and every year following has had the price increase by $100$ ISK.

The price of pizza can be written as follows:

$C = 1000 + 100(y - 2020), y \geq 2020$

where $C$ represents the cost of the pizza and $y$ the year we are given. This can be directly represented in code and printed out.

The constraints suggest that $\max y = 9999$, which maintains that $y \sim 10^3$. We can use at least $16$-bit signed integer to represent $y$, since

$10^3 < 3 \times 10^4 \approx 2^{15}-1 = 16 \textunderscore signed \textunderscore int \textunderscore max$

It is also suggested that $y \ge 2020$, but I have ran into errors with my code despite this. Instead, we need to add a conditional that the price at and before $2020$ is $1000$.

## Pseudo Code
```
INPUT y

IF y <= 2020:
    PRINT 1000
ELSE:
    PRINT 1000 + 100*(y - 2020)
```

## Time Complexity
We are only doing a fixed amount of arithmetic and read/print operations under a conditional, so the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.