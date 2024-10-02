# [Kiki Boba](https://open.kattis.com/problems/kikiboba)

This problem has an interest in naming conventions based on sharp, jagged objects (kiki) and smooth objects (boba). For our purposes, the character Fergus has determined that, based on the number of $b$'s compared to $k$'s in a word, we can categorize it as kiki or boba. Specifically, if the number of $b <$ number of $k$, we categorize it as `kiki`. If number of $k <$ number of $b$, we categorize it as `boba`. If number of $b =$ number of $k$, we categorize it as `boki`, and if there are no $b$'s or $k$'s, it is categorized as `none`. We must output the categorization.

We can iterate through the string and see when a character is a $b$ or $k$. We may use two variables that count for each one and then compare, or even slightly more clever is to use a single variable that increments for every $k$ and decrements for every $b$, or vice versa if you'd like. If negative, we know there's more $b$'s than $k$'s. If positive, we know the opposite is true. If $0$, we know there's an equal amount, but we don't know if there were any $b$'s or $k$'s.

To get around this, a boolean initialized to `FALSE` can be set before iterating through the string. When either a $b$ or $k$ is found, we can change this to `TRUE`, then after the string, check the value to see if a $b$ or $k$ was found. If not, we print the category `none`. With a $b$ counter and $k$ counter, we don't need this, and can merely check if either counter is $0$ to print `none`. Neither approach is significantly more efficient than the other.

The problem does not specify any more constraints, so it cannot be confidently said what should be considered, other than it's likely safe to assume the strings are not abnormally long. We do know they contain only the chars `a-z`.

## Pseudo Code
```
INPUT compString
b = 0, k = 0

FOR char IN compString:
    IF char == 'b':
        b++
    IF char == 'k':
        k++

IF b == 0 AND k == 0:
    PRINT "none"
ELSE IF b < k:
    PRINT "kiki"
ELSE IF k < b:
    PRINT "boba"
ELSE:
    PRINT "boki"
```

## Time Complexity
We are iterating through a string of length $n$, comparing each char to either $b$ or $k$. The complexity is therefore within $O(n)$. The comparisons at the end all take $O(1)$, and since we must check every character, this is exactly $\Omega(n) = \Theta(n)$ as well.