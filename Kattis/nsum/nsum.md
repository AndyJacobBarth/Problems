# [N-Sum](https://open.kattis.com/problems/nsum)

This problem gives us the amount of input $N$ followed by $N$ integers. We need to output the sum of all $N$ integers.

We have no further information on any relation to what the numbers will be, so we have no choice but to read all the input and add them together.

Since $N$ is not used in any further computations, we can use $N$ as an iterator for receiving the rest of the input in a while loop.

Fortunately, $2 \leq N \leq 10$ and each number is no greater than $1000$, so there aren't any serious limitations to consider.

## Pseudo Code
```
INPUT N
sum = 0

WHILE N > 0:
    INPUT num
    sum += num
    
    N--

PRINT sum
```

## Time Complexity
We need to read $N$ input and add each of them to an overall sum. Each arithmetic operation is $O(1)$. Input and output operations are $O(1)$, and since we must iterate through all numbers, the time complexity is exactly $O(N) = O(n) = \Omega(n) = \Theta(n)$.