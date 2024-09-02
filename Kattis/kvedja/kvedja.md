# [Kvedja](https://open.kattis.com/problems/kvedja)

The output is repeating the input while prepending the fixed string 'Kvedja,'. There is nothing to optimize or consider, as the name is expected to be English letters of no more than 100 characters.

## Psuedo Code
```
INPUT name
OUTPUT "Kvedja,\n" + name
```

## Time Complexity
This single print operation is exactly time complexity $O(1) = \Omega(1) = \Theta(1)$.
