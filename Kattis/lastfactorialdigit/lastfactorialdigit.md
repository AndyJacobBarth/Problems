# [Last Factorial Digit](https://open.kattis.com/problems/lastfactorialdigit)

This problem gives us a number of test cases $T$ where we must calculate $N!$ for each $N$.

The problem notes that $1 \leq T, N \leq 10$. $N$ is of particular interest here, because we could hardcode the results into the program. This would be the values:

| Number | Last Digit of Factorial |
|--------|-------------------------|
| 1      | 1                       |
| 2      | 2                       |
| 3      | 6                       |
| 4      | 4                       |
| 5      | 0                       |
| 6      | 0                       |
| 7      | 0                       |
| 8      | 0                       |
| 9      | 0                       |
| 10     | 0                       |

An observation we can make is that after $5$, the rest of the results are $0$. This is because within every factorial $5!$ and over, we have the numbers $2$ and $5$ in the product, making the result a multiple of $10$ and hence a last digit of $0$. We can now make conditional statements covering every case.

Since $T$ is not used in any computations, we can use it to iterate through the list of following inputs.

It's odd this problem has such a small amount of test cases. Much higher numbers can be used with the program maintaining efficiency. It would also better illustrate that the naive approach - multiplying all numbers $1$ to $N$ - is horribly inefficient. The naive approach is not illustrated.

## Pseudo Code
```
INPUT T

WHILE T > 0:
    INPUT N

    IF N == 1 OR N == 2 OR N == 4:
        PRINT N
    ELSE IF N == 3:
        PRINT 6
    ELSE:
        PRINT 0

    T--
```

## Time Complexity
We must read $T$ input and do no better, making the while loop $O(T) = O(n)$. Inside the loop is a fixed amount of conditionals that take $O(1)$ time, so overall the time complexity is exactly $O(n) = \Omega(n) = \Theta(n)$. We are only expecting at most $10$ test cases, so we will expect the program to be quick regardless.