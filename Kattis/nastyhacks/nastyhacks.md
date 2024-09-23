# [Nasty Hacks](https://open.kattis.com/problems/nastyhacks)

This problem gives us $n$ followed by $n$ cases of three variables - expected revenue without advertising $r$, expected revenue if advertising $e$, and cost of advertising $c$. We must output `advertise` if advertising is advantageous, `do not advertise` if it is not, or `does not matter` if advertising does not make a difference in revenue.

Since $n$ is not used for any computations, we can use it as an iterator with a while loop to extract the remaining input.

Determining whether we should advertise is a matter of seeing whether we get more money from advertising than not. In other words, if $e > r$. However, with advertising comes a cost that we must also consider, so more accurately we must determine whether $e - c > r$. We can use an if/else conditional statement to account for each scenario.

The constraints specify that $e, r, c \leq |10^6|$ where $e, r$ can be negative. It is best that we use a 32-bit signed integer for this problem because of the following:

$\max 32 \textunderscore signted \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^6 > 3 \times 10^4 \approx \max 16 \textunderscore signed \textunderscore int \textunderscore max$.

## Pseudo Code
```
INPUT n

WHILE n > 0:
    INPUT r, e, c
    
    IF e - c > r:
        PRINT "advertise"
    ELSE IF e - c < r:
        PRINT "do not advertise"
    ELSE:
        PRINT "does not matter"
    n--
```

## Time Complexity
We must read $n$ input and print out $n$ results within the while loop, resulting in $O(2n) = O(n)$ time given that input/output are $O(1)$ operations. We can do no better since each input has to be read. The comparisons within the while loop take $O(1)$ time, and there is at max $2$ comparisons with each iteration, so the comparisons only take $O(1)$ time overall with each loop. Therefore the total time complexity is $O(n) = \Omega(n) = \Theta(n)$.