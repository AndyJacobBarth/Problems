# [Laegd yfir landinu](https://open.kattis.com/problems/laegdyfirlandinu)

This problem gives us two integers $n, m$ followed by an $n \times m$ matrix of various pressure forecasts, each representing a different area. An area is said to have low pressure if it is lower than all of its orthogonal neighbors. If we find such an area, we print `Jebb`, and otherwise print `Neibb`.

The problem states that a low pressure area must have four orthogonal neighbors, and hints that the boundary can never be considered low pressure. This means we only have to check between $0 < i < n$ and $0 < j < m$.

We can loop through all $(n - 2) \times (m - 2)$ forecasts and check it's neighbors. This requires us to save all this data into our own two-dimensional array, which we can call `forecasts`.

For some forecast in $(i, j)$, we know its neighbors are the combinations $(i \pm 1, j \pm 1)$. If we bound our loops correctly, we won't have to check that the neighbors are out of bounds. From here, we make conditionals to check if all neighbors have a greater forecast than our current forecast in $(i, j)$. If so, we print `Jebb` and exit early. Otherwise, once all forecasts are exhausted, we print `Neibb`.

We should ask, "Can we do better?" It's hard to say. Since we are only comparing the values to the respective neighbors, we are finding a 'local minimum' and can't easily use previous information to build on this. Say we determine a value at $(i, j)$ is less than the value to the right of it $(i, j + 1)$ ($m$ in this problem iterates through the columns). We can store this information for $(i, j + 1)$ if we have to iterate to this value, but this is a check in order to reduce a check, which doesn't improve our functionality. I don't believe there is a better solution to this problem.

Fortunately, $n, m \leq 50$, so we aren't dealing with large data sets and must iterate through $48 \times 48$ forecasts at most. Each forecast can be up to $10^9$, so $32$-bit signed integers should be used here, as the following holds:

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^9 > 3 \times 10^4 \approx 2^{15}-1 = 16 \textunderscore signed \textunderscore int \textunderscore max$

## Pseudo Code
```
INPUT n, m

# Represents a two-dimensional array
forecasts = []

FOR i IN {0..n}:
    FOR j IN {0..m}:
        INPUT forecasts[n][m]

FOR i IN {1..n - 1}:
    FOR j IN {1..m - 1}:
        currentForecast = forecasts[i][j]

        IF (
            forecasts[i-1][j] > currentForecast AND
            forecasts[i+1][j] > currentForecast AND
            forecasts[i][j-1] > currentForecast AND
            forecasts[i][j+1] > currentForecast
        ):
            PRINT "Jebb"
            RETURN

PRINT "Neibb"
```

## Time Complexity
We must iterate through all $n \times m$ forecasts, which takes $O(n \times m)$ time. We also must compare the neighbors of all forecasts not within the boundary, checking $(n - 2) \times (m - 2)$ values, which is still on the order of $O(n \times m)$ in the worst case scenario that all values are checked. Even in the best-case scenario where the first forecast is found in $O(1)$ time, we can do no better than read all the forecasts first, so the overall complexity is exactly $O(n \times m) = \Omega(n \times m) = \Theta(n \times m)$.