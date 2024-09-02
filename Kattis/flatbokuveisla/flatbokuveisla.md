# [Flatbokuveisla](https://open.kattis.com/problems/flatbokuveisla)

This question is fancy phrasing for the modulus function. $n$ need not be greater than $m$ for this to still work. There is nothing special about the edge cases.  

The modulus operator is generally a costly operation, but because we don't know more information about these two numbers, we cannot make any optimizations to this problem.

## Psuedo Code
```
INPUT n, m
OUTPUT n % m
```

## Time Complexity
Because of using only a single operation, this is exactly $O(1) = \Omega(1) = \Theta(1)$.
