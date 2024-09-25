# [Chanukah](https://open.kattis.com/problems/chanukah)

In this problem, we extend the concept of the holiday Chanukah by asking how many candles are lit in total if one candle is lit on day $1$, two on day $2$, and so on, with an extra candle lit every evening. We are given $P$ denoting the number of following data sets, with the following $P$ lines giving us the order of the data set as $K$ and the number of days to consider as $N$. We are asked to output $K$ followed by the total number of candles lit if Chanukah lasted $N$ days.

A programmatic way of solving this is akin to the following mathematical representation of the solution in each data set:

$\sum_{i=1}^N i + N$

This can be executed by running a loop from $1$ to $N$, using an accumulator `sum` to add $i$ to it every time. Then we just add $N$ to the result.

A more efficient way is to use the mathematical property:

$\sum_{i=1}^N i = \frac {N(N+1)}2$

This is **Faulhaber's formula** of the form $\sum_{i=1}^N i^p$ for $p = 1$. This specific case is more generally known as the "sum of $N$ terms". With this, we can do three mathematical operations on a single variable instead of looping $N$ times, resulting in a faster program. In fact, the modified solution is now:

$\frac {N(N+1)}2 + N = \frac {N(N+1) + 2N}2 = \frac {N(N+1+2)}2 = \frac {N(N+3)}2$

We can directly output $K$ when receiving it, then do these calculations on $N$ and output the result each line.

Since $P$ is not used in any of our calculations, we can use it as an iterator through the rest of the input in a while loop.

The problem specifies that $P, N \leq 10^4$, and it is implied $K \leq 10^4$ as it is numbered $1$ to $P$, so we can use at least $16$-bit signed integers to represent them since

$10^4 < 3 \times 10^4 \approx \max 16 \textunderscore signed \textunderscore int \textunderscore max$

To minimize the time of the program, the C++ solution utilizes `std::ios::sync_with_stdio(0)` to ignore compatibility with C and C++ code and `std::cin.tie(0)` to untie `cin` with `cout`, improving I/O performance.

## Pseudo Code
Naive solution
```
INPUT P

WHILE P > 0:
    INPUT K, N
    sum = 0
    FOR j IN {1..N}:
        sum += j
    PRINT K + " " + sum
    P--
```
Optimized solution
```
INPUT P

WHILE P > 0:
    INPUT K N
    
    PRINT K + " " + N * (N + 3) / 2
    
    P--
```

## Time Complexity
The naive approach loops through $P$ input and has an inner loop that accumulates the numbers $1$ to $N$, thus executing $N$ times. This results in an algorithm of complexity $O(PN) = O(nm)$, where $n, m$. Because all input $P$ must be read and all numbers $1$ to $N$ are added without exception, this algorithm is also exactly $\Omega(nm) = \Theta(nm)$.

The optimized approach still must read $P$ input, but does a fixed amount of calculations on $N$ taking $O(1)$ time. We can do no better than read all $P$ data sets, so this results in time complexity of $O(P) = O(n) = \Omega(n) = \Theta(n)$.