# [Decimaldeletion]("https://open.kattis.com/problems/decimaldeletion")

This problem is simplified to a rounding problem for our input $N$. The problem is generous and will accept either input if the value is exactly between two integers.

We can use built-in rounding functions. Alternatively, we can create an if statement comparing if the first digit of $frac\{N\} > 5$. That is, we compare if the fractional part of $N$ is greater than $0.5$. If so, we round up, and otherwise we round down. Rounding down is the equivalent of truncating the number to only its integer part (denoted in pseudocode as `INT`), and rounding up is truncating the number and adding $1$. In most programming languages, the casting of a floating point to an integer is done by simply removing the fractional part.

There doesn't appear to be any edge cases to consider. Since $N \leq 10^4$, and is a floating point number, we should be able to accurately obtain $N$ with a normal `float` data type.

## Pseudo Code
```
INPUT N

IF FRAC(N)[0] >= 5:
    PRINT INT(N) + 1
ELSE
    PRINT INT(N)
```

## Time Complexity
`FRAC` and `INT` operations can be interpreted as taking $O(1)$ time. Reading the input is $O(1)$ time, since there is only one input. We also only do one comparison and one print operation in each path of the comparison, both taking $O(1)$ time. All of this combined makes the problem exactly $O(1) = \Omega(1) = \Theta(1)$ complexity.