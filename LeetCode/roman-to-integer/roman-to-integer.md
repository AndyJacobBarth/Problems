# [Roman-to-integer](https://leetcode.com/problems/roman-to-integer)

In this problem, we must convert Roman numerals from a string $s$ to integers. The problem explains what numeral corresponds to what integer value, and the unintuitive values like `IV` or `CD`.

The first step would be to make a mapping of the Roman numerals to integers. We need to determine whether we want to include a string like `IV` as its own separate block in the mapping. `I` would be mapped to `1` and `V` to `5`, but `IV` must evaluate to `4`. If we did this $2$-char mapping, we would still have to loop through every char, and the implementation would likely get unnecessarily complex.

Our mapping should consist of the following:

$I$ &rarr; $1$    \
$V$ &rarr; $5$    \
$X$ &rarr; $10$   \
$L$ &rarr; $50$   \
$C$ &rarr; $100$  \
$D$ &rarr; $500$  \
$M$ &rarr; $1000$

If Roman numerals weren't annoying, we'd be done. Unfortunately, we still have to take care of special cases. We have to check one char ahead for `I`, `X`, and `C`, and the respective numerals they potentially manipulate (`I` manipulates `V`, `X`; `X` manipulates `L`, `C`; `C` manipulates `D`, `M`). This can be done by making a somewhat verbose if/else statement.

Cleaner code would be to just check if the value of the next char is greater than the current. This shouldn't be noticeably better or worse, since they both do a small amount of $O(1)$ operations.

## Pseudo Code
```
INPUT s
s_length = LENGTH(s)
total = 0

numerals = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

FOR i IN {0..s_length}:
    # If statement spaced out for readability
    IF (
        s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X') ||
        s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C') ||
        s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')
    ):
        total += numerals[s[i + 1]] - numerals[s[i]]
        i++
    ELSE:
        total += numerals[s[i]]

PRINT total
```

## Time Complexity
The map that we created is a hash-map, that takes $O(1)$ time to extract from. We are reading a single string and printing a single integer, both taking $O(1)$ time. The for loop iterates through $n$ chars of $s$, with a fixed number of operations all taking $O(1)$ time, so the loop's time complexity is $O(n)$. We must iterate through each char (even when we hit the 'special' cases, we must look ahead at the next char), so our algorithm can do no better in the best case scenario. Therefore the total time complexity is exactly $O(n) = \Omega(n) = \Theta(n)$.