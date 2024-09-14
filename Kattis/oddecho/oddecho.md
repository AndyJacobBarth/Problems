# [Odd Echo](https://open.kattis.com/problems/oddecho)

This problem gives us the number of following inputs $n$, for which we must print out every odd-indexed input.

We can use a for loop that iterates by two, then print the odd input and ignore the even input. Since each input is on a new line, there isn't much we can do to filter the input during processing. Instead, we have to take the even-indexed input and effectively ignore it.

In the pseudocode, since $n$ is only used to interpret the number of following inputs, we use it as a decrementer in a while loop.

We should take into account that if $n$ is odd, decrementing by $2$ will eventually go to $1$. If we kept expecting an even and odd-indexed input, and have our condition set to when $n > 0$, our program will wait for one more even-indexed input that will never come. We can instead stop our while loop at $n \leq 1$, then check if $n$ is $1$ afterwards (and hence was initially an odd number). If so, we take in one more input that we will then print. For an even $n$, this conditional 

The constraints of the problem are very restricted, with $N \leq 10$ and each string of input being at most $100$ chars only containing 'a-z'. There isn't any major edge cases consider.

## Pseudo Code
```
INPUT n

WHILE n > 1:
    INPUT oddInput, evenInput
    PRINT oddInput
    n -= 2
IF n == 1:
    INPUT oddInput
    PRINT oddInput
```

## Time Complexity
We have to print out each odd input, with the print function interpreted as $O(1)$ time. In our loop, we are making $n / 2$ comparisons as $n$ is decremented by $2$ each time. These comparisons are on the order of $O(1)$. There is one additional comparison after the loop, which again is $O(1)$. 

We must read $n$ input and provide $n / 2$ prints, which is still on the order of $n$, so the overall complexity is exactly $O(n) = O(n) = \Omega(n) = \Theta(n)$.