# [Ameriskur](https://open.kattis.com/problems/ameriskur)

This problem simply gives us a measurement in football fields $n$ that we must convert to kilometers.

The conversion provided is:

$1 football field = 0.09144 km$.

We will take the input and multiply it by $0.09144$.

We see that $n \leq 10^5$, so we just need to make sure that we can take in input as 32-bit signed integer because of the following:

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^5 > 3 \times 10^4 \approx 16 \textunderscore signed \textunderscore int \textunderscore max$

We should also make sure we use approprate floating point arithmetic such that the precision is within $10^{-5}$. C++ will not by default give the precision needed (I tried), so the use of the `iomanip`'s `std::fixed` and `std::setprecision()` will help. Bash also needs this help with `%.xf` functionality for `printf` (also an alternative for C++). Python's default has sufficient precision.

## Pseudo Code
```
INPUT n
PRINT n * 0.09144
```

## Time Complexity
We are reading one input in $O(1)$, then performing one multiplication operation that is also considered $O(1)$. Printing the result is $O(1)$, so overall we have a time complexity of $O(1) = \Omega(1) = \Theta(1)$.
