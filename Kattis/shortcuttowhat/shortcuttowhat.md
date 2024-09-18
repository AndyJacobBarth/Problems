# [Shortcuttowhat]("https://open.kattis.com/problems/shortcuttowhat")

This problem gives us an integer $n$ and asks us to perform the following:

$3 \times (n + 5) - 10$

It's possible the challenge of this problem is to understand order of operations. We can directly output the result of performing these operations.

Since $n \leq |10^3|$, there are no serious data types or edge cases to consider.

## Pseudo Code
```
INPUT n
PRINT 3 * (n + 5) - 10
```

## Time Complexity
Input and output is fixed at one operation each, which is $O(1)$. We are also doing a fixed amount of arithmetic operations, each of which are $O(1)$, so the total time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.
