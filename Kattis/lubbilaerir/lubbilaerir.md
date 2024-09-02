# [Lubbilaerir](https://open.kattis.com/problems/lubbilaerir)

This problem just wants us to print the first char of a string.  

If the programming language permits, we can just expect one char input and ignore anything else, although the constraints specify the string is English letters of no more than 20 characters in length, so this optimization is not necessary. C++ and Bash support this, but Python does not have a built-in char type, and treats single characters as a string of length 1.

## Psuedo Code
```
INPUT object
OUTPUT object[0]
```

## Time Complexity
Extracting the first char of a string and printing it is exactly $O(1) = \Omega(1) = \Theta(1)$.
