# [Dragafra](https://open.kattis.com/problems/dragafra)

There are two integers provided, the number of windows covered by curtains n and number of window curtains drawn open m. It must be true that n > m, and the constraint shows 0 $\leq$ m $\leq$ n $\leq$ 10000. The edge cases aren't an issue for this problem.

The output is expected to be the number of windows still covered by curtains, so this is simply n - m.

## Psuedo Code
```
INPUT n, m

PRINT n-m
```

## Time Complexity
There are only ever two inputs that are subtracted from each other, so this is $O(1)$ = $\Omega(1)$ = $\Theta(1)$.
