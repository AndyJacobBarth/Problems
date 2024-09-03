# [Hipphipphurra](https://open.kattis.com/problems/hipphipphurra)

This problem asks us to print `Hipp hipp hurra, <name>!` For a given name for a given $x$ amount of times. This can be done straightforwardly using a for loop.

The constraints are english characters with an integer number for $x$. There does not appear to be any edge cases to consider.

## Psuedo Code
```
INPUT name, x
FOR i IN {1..x}:
    PRINT "Hipp hipp hurra, " + name + "!"
```

## Time Complexity
Because we must print a specified amount of times, we must take $n$ print operations, resulting in time complexity $O(n) = \Omega(n) = \Theta(n)$.