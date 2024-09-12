# [Skak]("https://open.kattis.com/problems/skak")

The problem involves a rook's position $x_h,y_h$ and a pawn's position $x_p,y_p$, the only two remaining pieces in a chess game. We must decide how many moves it will take the rook to take the pawn.

Since the pawn and rook are the only two pieces left, The rook will need to take at most two moves - selecting the correct file, and then selecting the correct rank. If the rook is on the same rank or file as the pawn, this only requires one move.

Using this logic, we just need to check if one of these scenarios holds. Otherwise we output the result of the alternate scenario. We can approach this by checking if $x_h$ matches $x_p$ or $y_h$ matches $y_p$. If so, we output $1$, and otherwise output $2$.

The problem states that the rook and pawn will never be on the same square, and otherwise there doesn't appear to be any substantial special cases.

## Pseudo Code
```
INPUT xh, yh, xp, yp

IF xh == xp OR yh == yp:
    PRINT 1
ELSE:
    PRINT 2
```

## Time Complexity
Because we only have to make at most two comparisons, each considered $O(1)$ complexity, the overall time complexity is $O(1) = \Omega(1) = \Theta(1)$.