# [Fjoldibokstafa]("https://open.kattis.com/problems/fjoldibokstafa")

This problem is concerned with the letter count of a given text $n$ consisting of one line and no whitespaces.

We can iterate through the entire string and only count lowercase/uppercase letters. It's possible to contain an array/set of A-Z/a-z. 

A slightly more optimized approach would be to check the ASCII numbering of each char. If it falls within the capital and lowercase ranges ($65-90$ and $97-122$ inclusive, respectively), then we can add that char to the count. This is more efficient since we only have to do a handful of comparisons (at most $4$ in the simplest implementation) as opposed to comparing at most $52$ different chars. Some programming langauges will even interpret comparison of chars by their ASCII numerical value.

ASCII symbols are guaranteed as the input, so the second method mentioned works. Otherwise, there is no specific handling we have to check.

## Pseudo Code
Using a letter array:
```
INPUT n
letters = "ABC...Zabc...z", count = 0

FOR char IN n:
    FOR letter IN letters:
        IF char == letter:
            count++
PRINT count
```

Using ASCII numbering:
```
INPUT n
count = 0
FOR char IN n:
    IF char < 123 AND char > 96:
        count++
    IF char > 64 AND char < 91:
        count++

PRINT count
```

## Time Complexity
Since we have no choice but to loop through the entire string of length $n$, the best acse is $\Omega(n)$. Because we do a fixed amount of comparisons for each char, these comparisons are effectively $O(1)$, resulting in a time complexity of $O(n) = \Omega(n) = \Theta(n)$.