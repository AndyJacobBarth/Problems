# [Umferd(https://open.kattis.com/problems/umferd)

This problem is a traffic problem providing us with the length of the lanes $m$ and the number of lanes $n$. We are then provided with an ASCII representation of cars (#) and empty spots (.) based on an $n \times m$ representation. We must find the proportion of empty spaces to an accuracy of $10^{-5}$.

We can multiply $n$ and $m$ to get the denominator of our overall proportion. Once $n$ is used, it is no longer needed, and can be used as our iterator. Then we can count the number of '.'s for our numerator, and finally perform division. The main thing to consider now is how to check for all '.'s.

We can treat each $n$ lines as a string, and iterate through them for the occurrence of every '.'.

We know from the problem that $ 1 \leq n, m \leq 500$, so we should not be concerned with any limitations here. If $n$ was very large, we could consider using a more efficient approach at minimizing the I/O by interpreting everything after $n, m$ as one input, but this is unnecessary. The total string length we are interpreting will be:

$\max \{ n \} \times \max \{ m \} = 500 \times 500 = 2.5 \times 10^5$.

For the C++ solution, I used `cin.tie()` and `ios::sync_with_stdio()` to improve I/O speeds, as otherwise best peformance resulted in $0.01s$.

While the C++ and Python code works, the Bash script takes too long, particularly with test case #50. My initial code read each $n$ lines, and I attempted to optimize it using `cat` with no success. Attempts at specifying the precision or using `awk` to count '.'s did not work either (and gave incorrect output, but only for test case #50). 

I don't know at this time why this is, and I don't believe there's any algorithmic optimizations, but I will leave it as an exercise to the reader to optimize this code. In this repository, the Bash code I've left currently exceeds the time requirements.

## Pseudo Code
```
INPUT m, n
totalSpace = m * n, availableSpace = 0

WHILE n > 0:
    INPUT traffic
    FOR spot IN traffic:
        IF spot == '.':
            availableSpace++
    n--
PRINT availableSpace / totalSpace
```
Since we must iterate through every ASCII char to determine if it is a '.', we have no choice but to check all $n \times m$ chars, resulting in complexity $O(n \times m) = \Omega(n \times m) = \Theta(n \times m)$.