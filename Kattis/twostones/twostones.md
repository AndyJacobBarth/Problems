# [Twostones](https://open.kattis.com/problems/twostones)

This problem rests on a game between Alice and Bob, where there are $N$ stones on the ground in a line, and they can take turns removing two consecutive stones until either all of them are gone or each stone has a gap between them. We need to print the name of the winner, with an odd number of stones left being Alice and an even number of stones left being Bob. Alice gets to start each game.

From the given input/output, intuitively we may guess that if there's an even number of stones to begin, Bob will win, and Alice will win if there's an odd number. This means that with an odd number of stones to begin with, an odd number of stones will be left, and Alice wins.

The solution arises from the simple fact that they are always removing two stones no matter what. If we start with an even number of stones, always removing two stones will still result in an even number of stones. The same applies if we begin with an odd number of stones. Therefore we only need to check if the initial input is even or odd.

Depending on the optimization of the compiled programming language, modularity could be used for readability. The most efficient way would be to use low-level operations like bitmasking. If a number is even, it's bit string will end in a $1$, and end in a $0$ if odd. We can check this by using the bitwise `&` operation on the input and $1$.

We should note that $N \leq 10^7$. It would be safest to use a 32-bit signed integer here ($2^{31} - 1 > 2 \times 10^9 > 10^9 > 10^7 \geq N$)

## Psuedo Code
Using modulo operator:
```
INPUT N
IF N % 2 == 1:
    PRINT("Alice")
ELSE:
    PRINT("Bob")
```
Using bitwise `&`:
```
INPUT N
IF N & 1 == 1:
    PRINT("Alice")
ELSE:
    PRINT("Bob")
```
## Time Complexity
Because we are doing a comparison on a single integer, this has complexity $O(1) = \Omega(1) = \Theta(1)$.