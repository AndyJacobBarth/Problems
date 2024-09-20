# [Tarifa](https://open.kattis.com/problems/tarifa)

In this problem, we are given $X$, the number of MBs alloted per month for our protagonist Pedro to use on his phone, followed by $N$, the number of months he's used the plan, and $P_1,...,P_N$ the MBs used each month. We must determine the MBs he will have available on month $N + 1$. We can assume $P_i$ will never be greater than what Pedro has available to him.

We can see how much he's used by calculating how much MBs he's been allotted throughout the months - $X * N$ - minus what he's used - $\sum_{i=1}^N P_i$. He will also obtain $X$ more MBs for month $N + 1$, so we can add this in. This will give us our desired result:

$X * N - \sum_{i=1}^N P_i + X$ \
$= X * (N + 1) - \sum_{i=1}^N P_i$

When programming this, we just calculate $X * (N + 1)$ in some variable `answer` and then loop through the remaining input, subtracting it from `answer`.

Once we calculate $X * (N + 1)$, then $N$ is no longer used and we can use it as an iterator through a while loop to get the rest of the input.

The largest value in this problem is $P_i \leq 10^4$, which is feasible by using at least $16$-bit signed integer values. There are no edge cases to consider.

## Pseudo Code
```
INPUT X, N

answer = X * (N + 1)

WHILE N > 0:
    INPUT P
    answer -= P
    N--

PRINT answer
```

## Time Complexity
The input and output, along with arithmetic operations, all take $O(1)$. We must read the $N$ input without any advanced knowledge of what these values are, so we can do no better than this. This results in an overall time complexity of $O(N) = O(n) = \Omega(n) = \Theta(n)$.