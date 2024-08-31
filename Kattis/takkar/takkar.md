# [Takkar](https://open.kattis.com/problems/takkar)

This problem is a simple conditional problem. We have two inputs - Trump and Kim Jong-Un's button size ($a$ and $b$, respectively) to launch nuclear weapons, which I suppose is suggested as being proportional the number of nuclear warheads they would be launching. This is a somewhat oddly political problem.  

The output is based on conditionals. If Trump's button is larger, we print `MAGA!`, if Kim's is larger we print `FAKE NEWS!`, and if they're equal we print `WORLD WAR 3!`. This calls for an if/else if/else statement. It does not matter the order that we put these conditionals.

Edge cases are of no concern either. $0 \leq a, b \leq 10^9$, so as long as the integer data type we're using is 32-bits ($2^{32} \approx 2 \times 10^9 > 10^9$).

## Psuedo Code
```
INPUT a, b
IF a > b:
    PRINT "MAGA!"
ELSE IF b > a:
    PRINT "FAKE NEWS!"
ELSE
    PRINT "WORLD WAR 3!"
```

## Time Complexity
Since we are only comparing with one operation, the time complexity is $O(1) = \Omega(1) = \Theta(1)$.