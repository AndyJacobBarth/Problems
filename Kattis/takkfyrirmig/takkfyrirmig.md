# [Takkfyrirmig](https://open.kattis.com/problems/takkfyrirmig)

In this problem, we are simply outputting `Takk <name>` for different names provided.

We can write a simple for loop for our program. Since the first input specifies the number of following inputs and is not used anywhere else, we can use a decrementing while loop.

There are no constraints or edge cases to consider. $n$ is small enough that it can be stored within a data type of at least a 16-bit signed integer (maximum of this type is $2^{15} - 1 \gt 2^{10} > 10^3 \gt n$).

## Psuedo Code
```
INPUT n
WHILE n > 0:
    INPUT name
    OUTPUT "Takk name"
    n--
```

## Time Complexity
Because we must iterate through each $n$ names, this requires time complexity of exactly $O(n) = \Omega(n) = \Theta(n)$.