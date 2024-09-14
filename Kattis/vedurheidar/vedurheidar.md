# [Vedurheidar(https://open.kattis.com/problems/vedurheidar)

This problem gives us the current windspeed $v$ in Iceland, along with a number of roads $n$. The following $n$ input is a road name $s_i$ and their respective maximum safe wind speeds $k_i$. We must print each road and whether it is safe (`lokud`) or unsafe (`opin`) to drive.

Knowing whether it is safe or unsafe to drive is a matter of comparing $k_i$ with $v$. If $v > k_i$, it is unsafe, and safe otherwise.

Since $n$ is not used in any further computations, we can use it to loop through the remaining input.

The inputs are all fairly small, of no magnitude greater than in the order of $10^2$. We won't entertain data type restrictions here, as 8-bit data types could even be used. There does not appear to be any edge cases to consider.

## Pseudo Code
```
INPUT v, n

WHILE n > 0:
    INPUT s, k

    IF v > k:
        PRINT s + "lokud"
    ELSE:
        PRINT s + " opin"
    n--
```

## Time Complexity
Our read for the first two input takes complexity $O(1)$.

For each $s, k$, we are doing one comparison and one print operation, each being $O(1)$. Since we must loop through all $n$ roads, the overall time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.