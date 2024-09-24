# [Qaly](https://open.kattis.com/problems/qaly)

We are given $N$ representing the number of following lines of input. In each of these lines, we have the quality of one's life $q$ and their lifetime in years $y$. We must calculate the overall quality of life `QALY` of the history of a person.

The problem also gives how to calculate `QALY`, which is just $q \times y$. We just need to add all of the products of input:

$\sum_{i=1}^N q_i \times y_i$

In a program, this is just a simple loop. Since $N$ is not used in the computation itself, we can use it as the iterator using a while loop. We can initialize a variable `sum` that will act as an accumulator of all the values we calculate.

The constraints are so small that they are not worth considering. Our values $q, y$ are floating point, so we need to ensure floating point arithmetic is done. The precision need only be up to $10^{-3}$, so we don't need to worry much about this. There are no edge cases that we need to consider.

## Pseudo Code
```
INPUT N
sum=0

WHILE N > 0:
    INPUT q, y
    sum += q * y

    N--

PRINT sum
```

## Time Complexity
We must read through $N$ input, each in $O(1)$ time, requiring a loop taking time $O(N)$. Since all input needs to be read, we can do no better than this. Adding to `sum` takes $O(1)$ time in each iteration, and the final printing of `sum` is $O(1)$ time. Therefore the overall time complexity is $O(N) = O(n) = \Omega(n) = \Theta(n)$.

We should note that while the analysis states this is $\Theta(n)$, there is only up to $100$ input with calculations on numbers no greater than $100$, so the result will still be fairly quick.