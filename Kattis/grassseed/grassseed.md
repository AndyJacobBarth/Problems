# [Grass Seed](https://open.kattis.com/problems/grassseed)

The essence of this problem is to output the total cost of sowing $L$ lawns, given that $C$ is the cost per square meter. We are given $C$ and $L$ followed by $L$ lines denoting each lawn's width $w_i$ and length $l_i$.

The cost is per unit of area, so we just need to find the total area and multiply it by the cost. We can find the area of each lawn 

$A_i = w_i \times l_i$

Then add the areas of each lawn to get the total area. Multiply this by the cost per area $C$ and we get the total cost:

$C \times \sum_{i=1}^L A_i = C \times \sum_{i=1}^L (w_i \times l_i)$

In a program, this amounts to looping through $L$ lines and accumulating the product of the two given numbers in a reserved variable `totalArea`. After the loop is done, we can print the result multipled by $C$.

Since $L$ is not actually used in the computations at all, we can use it to iterate through the input, decrementing it in a while loop.

All input is given to be $\leq 100$, but we need to ensure our precision is no worse than $10^{-6}$. C++ can handle this with the `iomanip` library, specifically with `std::fixed` and `std::setprecision`. Bash's `awk` command can specify this with `printf %.xf`, which is akin to C++'s `printf` function that can be used as well. Python has sufficient precision for this problem by default.

When reading $l_i$ and $w_i$, I have it switched in my code, but this does not have any major effect, since number multiplication is commutative. To demonstrate this, and partly because I am lazy, I have left this unchanged.

## Pseudo Code
```
INPUT C, L
totalArea = 0

WHILE L > 0:
    INPUT l, w
    totalArea += l * w
    L--

PRINT C * totalArea
```

## Time Complexity
We are looping through $L = n$ input, resulting in $O(n)$ time complexity. Since we have no further information on what the dimensions of the lawns will be, this is the best we can do, and so our algorithm is exactly $\Omega(n) = \Theta(n)$.