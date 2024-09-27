# [Adding Trouble](https://open.kattis.com/problems/addingtrouble)

This problem gives us three integers $A, B, C$. We should output `correct!` if $A + B = C$ and `wrong!` otherwise.

This is straightforwardly executed by using a conditional checking if $A + B = C$.

The problem states that $A, B, C \leq |10^9|$, so we should make sure that $A, B, C$ are at least $32$-bit signed integers, since

$\max 32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^9 > 3 \times 10^4 \approx \max 16 \textunderscore signed \textunderscore int \textunderscore max$

## Pseudo Code
```
INPUT A, B, C

IF A + B == C:
    PRINT "correct!"
ELSE:
    PRINT "wrong!"
```

## Time Complexity
We have fixed number of input with one conditional and one arithmetic operation, so therefore the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.