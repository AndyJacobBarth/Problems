# [Knight Packing](https://open.kattis.com/problems/knightpacking)

This problem addresses two players that must place knights on an $N \times N$ chess board. The catch is that no knights can be a knights move away from each other. The player who cannot place a knight on the board loses. We must output `first` if the first player wins, or `second` if the second player wins, given the size of the board.

One thing we can generalize is that if we are able to determine the final result of knights, we know that an odd number of knights implies player one wins. An even number implies player two wins. This is due to the nature of the game, where the turns alternate between the two players, and the fact that one knight is placed each turn.

As the problem is stated, there is not enough information given. Let's see why by looking at the first few examples. For $N = 1$ and $N = 2$, we get a trivial setup:

```
+--+     +--+
|  | --> |♞|
+--+     +--+
```
Here, a `.` represents an empty spot and `x` represents a knight. For this $1 \times 1$ setup, it's clear only one knight can be placed, and therefore player one wins.
```
+--+--+     +--+--+  
|  |  |     |♞|♞|
+--+--+ --> +--+--+
|  |  |     |♞|♞|
+--+--+     +--+--+
```
For a $2 \times 2$ board, it is impossible for a piece to be a knight's move away from another piece - this requires at least a $3 \times 3$ board. Therefore we can always fill the board up with knights, and having four knights means player two wins.

Now let's look at $N = 3$:

```
+--+--+--+     +--+--+--+     +--+--+--+
|  |  |  |     |  |  |  |     |♞|  |♞|
+--+--+--+     +--+--+--+     +--+--+--+
|  |  |  | --> |  |♞|  | --> |  |♞|  |
+--+--+--+     +--+--+--+     +--+--+--+
|  |  |  |     |♞|♞|♞ |     |♞|  |♞|
+--+--+--+     +--+--+--+     +--+--+--+
```

Above I've illustrated two different solutions. In the first solution, only four pieces are placed, and no more can be added, as adding a piece in any available slot will make it a knight's move away from another piece. In the second solution, five pieces are placed, and it is a valid possibility. If there's a solution with four pieces on the board, that means player two would win. We also see a solution with five pieces, implying player one wins. How can we have two possible solutions?

The problem falls apart here, and it's frustrating. Are we to assume that players one and two play optimally? If so, the solution is far from obvious here. We would have to analyze all the ways player one and two can play. We will analyze this at the end.

For now, we must assume what is not obvious - we must assume that a maximum number of knights are placed. This is so problem breaking that it ruins the narrative of the problem. There is no need to phrase this as a game between two players, as we could've stated the problem with this rule and the knight's move rule and be done.

If we assume this, we can approach this problem as intended. A chess board is typically separated by two colors, say black and white. Black squares on a board are always diagonally connected to each other as are white squares to each other. Another way to view it is that black squares are orthogonally surrounded by white squares, and white squares are orthogonally surrounded by black squares. Below is a poor attempt at me illustrating this with a $6 \times 6$ board.

```
+---+--+---+--+--+---+
|⚪|⚫|⚪|⚫|⚪|⚫|
+---+--+---+--+--+---+
|⚫|⚪|⚫|⚪|⚫|⚪|
+---+--+---+--+--+---+
|⚪|⚫|⚪|⚫|⚪|⚫|
+---+--+---+--+--+---+
|⚫|⚪|⚫|⚪|⚫|⚪|
+---+--+---+--+--+---+
|⚪|⚫|⚪|⚫|⚪|⚫|
+---+--+---+--+--+---+
|⚫|⚪|⚫|⚪|⚫|⚪|
+---+--+---+--+--+---+
```

We can observe that a knight's move always results in being on the opposite color. Remaining on a color results in moving in $1$ direction east-west and $1$ direction north-south, hence remaining on the same color. A knight's move adds $1$ more unit to move in either east-west or north-south, but not both, so after moving diagonally, you *must* move orthogonally. This means you will result in the opposite color's square.

With that, our next observation is that we can put knights all on the same color and obey the knight's move constraint - quite a lot of knights, actually. 

```
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
```

This will either be half of all the spaces in a chess board if $N$ is even, and hence $\frac {N^2} 2$ knights placed, or $\frac {N^2 \pm 1}2$ pieces on the board if $N$ is odd (actually, $N=3$ is always $\frac {N^2 + 1}2$ because the center cannot see any squares a knight's move away, but this does not affect our results). Assuming we're trying to maximize the number of pieces on the board, we can drop the minus sign and make it $\frac {N^2 + 1}2$.

Another observation is that this indeed *is* the maximum number of knights we can place. By placing a knight on every square of one color, it's impossible to place a knight on the other color, so we can do no better. If we try to have knights on both colors, we will not be able to get as many as we have with one color. 

To see this, set a knight on all squares of the same color - let's say black. Then set a knight on any white square, removing the pieces a knight's move away from this one to obey the rules. We have added one piece, but must take away multiple knights to do this. The minimum knights we would be able to remove is by assuming we add a knight in the corner, which would see two squares that we couldn't allow pieces to go on. This results in an informal proof by contradiction (again, $N = 3$ is an exception specifically because the center cannot see any more squares a knight's move away - but this does not have any impact on the solution).

Here again is our maximum placement:
```
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
```

Now let's minimize removing any knights by placing one knight in the corner that we haven't used:
```
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|♞|♞|  |♞|  |♞|
+--+--+--+--+--+--+
 ^^
```

This knight sees two other knights, so we must remove them:

```
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |♞|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |♞|  |♞|  |
+--+--+--+--+--+--+
|  |xx|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |xx|  |♞|  |
+--+--+--+--+--+--+
|♞|♞|  |♞|  |♞|
+--+--+--+--+--+--+
```

Trying to continue this process will only lead to even more removal of pieces. We're not going to do any better than our same-color approach.

Now that we've established the maximum number of knights placed, our final observation is that we have two scenarios:

(1) $N$ is even and the maximum number of pieces placed is $\frac {N^2}2$

(2) $N$ is odd and the maximum number of pieces placed is $\frac {N^2 + 1}2$

Let's look at case $1$. Let $N = 2k$, then 

$N^2 = 4k^2$ 

and 

$\frac {N^2}2 = 2k^2$. 

So, $\frac {N^2}2$ is divisible by $2$ and is even, therefore player two always wins.

Next, let's look at case $2$. Let $N = 2k+1$. Then 

$N^2 = 4k^2 + 4k + 1$ 

and 

$N^2 + 1 = 4k^2 + 4k + 2 = 2(2k^2 + 2k + 1)$.

Finally,

$\frac {N^2 + 1}2 = 2k^2 + 2k + 1 = 2m + 1$, where $m = k^2 + k$.

So $\frac {N^2 + 1}2$ is odd, therefore player one always wins.

Unfortunately, the problem was worded terribly, and although mathematically proving the solution is satisfying, the problem is deemed easy because it can be easily guessed that this is the case by looking at the given test cases.

Let's take a step back. The problem may expect us to observe the following: when a knight is placed, it can see either two squares by being in the corner, four squares by being on the edge, six squares by being spaced slightly away from the edge, or eight squares by being in the center. 

```
+--+--+--+--+--+--+
|♞|  |  |  |  |  |
+--+--+--+--+--+--+
|  |  |xx|  |  |  |
+--+--+--+--+--+--+
|  |xx|  |  |  |  |
+--+--+--+--+--+--+
|  |  |  |  |  |  |
+--+--+--+--+--+--+
|  |  |  |  |  |  |
+--+--+--+--+--+--+
|  |  |  |  |  |  |
+--+--+--+--+--+--+

+--+--+--+--+--+--+
|  |xx|  |  |  |  |
+--+--+--+--+--+--+
|  |  |xx|  |  |  |
+--+--+--+--+--+--+
|♞|  |  |  |  |  |
+--+--+--+--+--+--+
|  |  |xx|  |  |  |
+--+--+--+--+--+--+
|  |xx|  |  |  |  |
+--+--+--+--+--+--+
|  |  |  |  |  |  |
+--+--+--+--+--+--+

+--+--+--+--+--+--+
|xx|  |xx|  |  |  |
+--+--+--+--+--+--+
|  |  |  |xx|  |  |
+--+--+--+--+--+--+
|  |♞|  |  |  |  |
+--+--+--+--+--+--+
|  |  |  |xx|  |  |
+--+--+--+--+--+--+
|xx|  |xx|  |  |  |
+--+--+--+--+--+--+
|  |  |  |  |  |  |
+--+--+--+--+--+--+

+--+--+--+--+--+--+
|  |xx|  |xx|  |  |
+--+--+--+--+--+--+
|xx|  |  |  |xx|  |
+--+--+--+--+--+--+
|  |  |♞|  |  |  |
+--+--+--+--+--+--+
|xx|  |  |  |xx|  |
+--+--+--+--+--+--+
|  |xx|  |xx|  |  |
+--+--+--+--+--+--+
|  |  |  |  |  |  |
+--+--+--+--+--+--+
```

By observing the maximum number of knights we place, say, on the black spaces, if we add a knight on a white space, we must remove an even number of knights on the black spaces. $even - even = even$, and $odd - even = odd$, so the number of pieces remain even or odd - whichever we've determined. This would lead us to the conclusion that even without optimal play, player one will always win when $N$ is odd and player two will always win when $N$ is even. Sounds good, right? No.

Don't forget that we already disproved this for $N = 3$, however we know that this is a special case, as we've outlined twice already because its center doesn't see any squares a knight's move away. Does that mean this holds true for every $N$ not equal to $3$? Well, what if placing knights on white squares double eliminate a square? As shown below, this results in an odd number of pieces eliminated. Since $even - odd = odd$ and $odd - odd = even$, there exist arrangements that do not guarantee player one's win or player two's win.

```
+--+--+--+--+--+--+
|  |xx|  |  |  |  |
+--+--+--+--+--+--+
|  |  |xx|  |  |  |
+--+--+--+--+--+--+
|♞|  |  |xx|  |xx|
+--+--+--+--+--+--+
|  |  |xx|  |  |  |
+--+--+--+--+--+--+
|  |xx|  |  |♞|  |
+--+--+--+--+--+--+
|  |  |xx|  |  |  |
+--+--+--+--+--+--+
```

Here, a $6 \times 6$ board would normally mean player two would win, but this duplicate elimination takes out an odd number of squares. Now if we try to place pieces on the diagonals, player one would win with a placement of $13$ knights:

```
+--+--+--+--+--+--+
|  |xx|  |♞|  |♞|
+--+--+--+--+--+--+
|♞|  |xx|  |♞|  |
+--+--+--+--+--+--+
|♞|♞|  |xx|  |xx|
+--+--+--+--+--+--+
|♞|  |xx|  |♞|  |
+--+--+--+--+--+--+
|  |xx|  |♞|♞|♞|
+--+--+--+--+--+--+
|♞|  |xx|  |♞|  |
+--+--+--+--+--+--+
```

What about strictly optimal play? This is not an easy answer. We've found a guaranteed way for a player to win. Depending on the size of the board, one of the two players wants the board to have the maximum possible number of pieces it can hold, because the parity would match that of the number of turns the players would make. In other words, an odd $N$ would mean player one desires the maximum number of pieces to be on the board, whereas an even $N$ would mean player two wants this to happen.

As the opposing player, you don't want this to happen. Instead, you'll place knights such that they will remove an odd number of squares using the duplicate spacing we mentioned in our last diagram. Of course, the player that wants the maximum pieces to be placed can thwart this by making duplicates themselves, canceling out what the opposing player has done. 

Is it possible that this can be canceled out every time? If so, this would be a strong indication that optimal play will result in the same answer we've expected. I will leave it as an exercise to the reader to determine this.

As to actually programming the solution, we simply figure out if $N$ is divisible by $2$ to print `second`, and otherwise print `first`. We can optimize this using bitmasking, using the bitwise operation 'AND' with $1$ and $N$. Since `x & 0 == 0` and `x & 1 == x`, We will get a $1$ if $N$ is odd and $0$ if $N$ is even.

## Pseudo Code
```
INPUT N

IF N & 1 == 1:
    PRINT "first"
ELSE:
    PRINT "second"
```

## Time Complexity
Since we are using a conditional on one input, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.