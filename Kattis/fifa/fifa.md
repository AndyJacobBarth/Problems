# [Fifa](https://open.kattis.com/problems/fifa)

This problem gives us two inputs $n$ and $k$. Leaving out some details, we are starting at the year $2022$ and need to determine the current year based on the $n$ improvements that occurred when $k$ improvements occur per year.

This is simply $ 2022 + n/k $. It should be safe to assume that we should always expect an integer output, as it should represent the 'current' year.

 $ n \leq 2 \times 10^9 $, so we should make sure that $n$ is at least an unsigned 32-bit integer ($ 2^{31} - 1 > 2 \times 10^9 \geq n $). $k$ is much less of a concern as $ k \leq 10^3 $ and must be at least a signed 16-bit integer ($ 2^{15} - 1 > 2^{10} > 10^3 $).

## Psuedo Code
```
INPUT n, k
OUTPUT 2022 + n/k
```

## Time Complexity
Because we have exactly two inputs with one addition and one division operation, this is exactly $ O(1) = \Omega(1) = \Theta(1) $.