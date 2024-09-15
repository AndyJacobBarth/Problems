# [Millifaersla](https://open.kattis.com/problems/millifaersla)

In this problem, it asks us to print one of three names depending on who has the lowest integer (transaction fee, in the context of the problem). The inputs, respectively, are $a$ for Monnei, $b$ for Fjee, and $c$ for Dolladollabilljoll.

Because there are only 3 options, we just need to compare them in any order. No matter how we approach this, it will be a fixed number of if/else statements. A 'naive' approach is to have three cases comparing one of the inputs to the other two (e.g. IF $a < b$ AND $a < c$, fully shown below). While this code looks more concise and readable (and definitely should be preferred if we weren't trying to optimize), the worst case would require three comparisons.

The more optimized approach is to influence our behavior based on what we've compared. We first make a comparison between two of the inputs, then a comparison on the third input based on that result. It is much easier to compare the pseudo code for the two down below. It is important to note that this difference is extremely minimal, as it only takes out one comparison operator. If we were given even more input, this could be refined further. This optimization is a divide-and-conquer approach, effectively comparing half of the input, whereas the naive approach compared $n - 1$ inputs. This analysis is already overkill, so I'll withhold further analysis for a problem that would more benefit from it.

The constraints require $a,b,c \leq10^9$, which only means we need to make these integers at least 32-bit unsigned int ($2^{31} - 1 > 2 \times 10^9 > 10^9 >= a,b,c$). The question does not specify output for a case where $a = b = c$, and it should be safe to ignore.
## Psuedo Code
Naive approach:
```
INPUT a,b,c
IF a < b AND a < c:
    PRINT "Monnei"
IF b < a AND b < c:
    PRINT "Dolladollabilljoll"
ELSE:
    "Fjee"
```
Optimized approach:
```
INPUT a,b,c

IF a < b:
    IF a < c:
        PRINT "Monnei"
    ELSE:
        PRINT "Dolladollabilljoll"
ELSE IF b < c:
    PRINT "Fjee"
ELSE
    PRINT "Dolladollabilljoll"
```

## Time Complexity
Because there are only ever two comparisons with a fixed number of inputs, this is of time complexity $O(1) = \Omega(1) = \Theta(1)$.