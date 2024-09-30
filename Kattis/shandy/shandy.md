# [Shandy](https://open.kattis.com/problems/shandy)

This problem introduces the concept of the alcoholic beverage Shandy. For our purposes, we know we can make two Shandies with one bottle of beer and one bottle of lemonade. We are given $B$ bottles of beer and $L$ bottles of lemonade, and must determine the number of Shandies we can make.

We need to determine whether the beer or lemonade is a limiting factor. If we have plenty of beer but only a little lemonade, we can only make as many Shanties as we have lemonade. Therefore we need to use a conditional that determines whether we have less beer or less lemonade. Whichever is the least is our limiting factor.

Since we can make two shandies per beer/lemonade, we know we can make $2 \times limiting factor$. All we have to do is output this result.

Since $B, L \leq 10^2$, it's not worth considering what data types are needed here. There are no edge cases to consider, as if $B$ or $L = 0$, we will get $2 \times 0 = 0$ as our output, which is correct. It is also not necessary to check whether $B$ or $L$ are equal, as we can use either value in this case.

A very slight optimization can be to use bit shifting. Shifting left by $1$ is the same as multiplying by $2$ for integers. This type of low-level optimization is usually already done by a compiler, and will not give significant performance improvement.

## Pseudo Code
```
INPUT B, L

IF B < L:
    PRINT 2*B
ELSE:
    PRINT 2*L
```

## Time Complexity
Since we are only doing one comparison and one arithmetic operation, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.