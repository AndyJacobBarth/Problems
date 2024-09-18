# [Betting](https://open.kattis.com/problems/betting)

The problem statement is influenced by the functionality of betting channel points on Twitch, but in a copyright-friendly way. It asks that between two options, if a percentage $a$ of switch points was put on the first option, what would be the ratio of return for the first and second options, respectively?

This is a matter of the proportion of votes to the whole. In other words, out of $100\%$, $100 / a$ gives the return on option $1$ and $100 / (100 - a)$ gives the return on option $2$.

Since $a$ is $0 \leq a \leq 100$, data types are of no concern. We just need to make sure our output is a float, and that the precision is at least $10^{-3}$ as specified within the problem.

## Pseudo Code
```
INPUT a

PRINT 100 / a
PRINT 100 / (100 - a)
```

## Time Complexity
We have a fixed amount of input, print, and arithmetic operations, each of $O(1)$, so the overall time complexity is $O(1) = \Omega(1) = \Theta(1)$.