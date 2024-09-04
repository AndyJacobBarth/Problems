# [Blandadbest](https://open.kattis.com/problems/blandadbest)

This problem is interesting in its simplicity. It will give us an integer $n$, $1$ or $2$, specifying the number of following outputs, which are unique types of meat. It wants us to output the name of the meat if $ n = 1 $ or `blandad best` if $ n = 2 $.

We can check to see if we are expecting one input. If we are, we can immediately print it as the output. Otherwise, we can immediately print the two types of meat, as there are only two types and the inputs must be unique.

Alternatively, we could ignore the integer input entirely and always print everything that follows. Some languages will permit this, but for simplicity, I only consider the first approach.

## Psuedo Code
```
INPUT n

IF n == 1:
    INPUT meat
    PRINT meat
ELSE
    PRINT "blandad best"
```

## Time Complexity
Because we are doing one comparison and one print operation, this is easily $ O(1) = \Omega(1) = \Theta(1) $.