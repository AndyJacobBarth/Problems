# [Timeloop](https://open.kattis.com/problems/timeloop)

This problem gives us a single input $N$ and expects a listing from $1$ to $N$ followed by the phrase `Abracadabra` each time.

This simply requires a for loop. 

## Psuedo Code
```
INPUT N
FOR i IN {1..N}:
    PRINT i + " Abracadabra"
```

## Time Complexity
Because we must print $N = n$ times, this becomes time complexity of $O(n) = \Omega(n) = \Theta(n)$.