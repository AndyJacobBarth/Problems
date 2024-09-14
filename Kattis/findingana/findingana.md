# [Findingana(https://open.kattis.com/problems/findingana)

In this problem, we must look at a string from chars $s_1, ..., s_i$ such that we print the string after the first occurrence of the letter 'a'. We are guaranteed the letter 'a' will be within the string.

This problem is pretty straightforward, and there's no real way to optimize this. Logically it would benefit us to start our search in the beginning, and we must iterate through chars until we hit the letter 'a', then output the remaining substring.

We could use a boolean to evaluate to 'True' when we use a conditional to find an occurrence of 'a'. A simple implementation will continue to check if 'a' is found redundantly. This is shown in the first pseudocode as a 'naive' approach.

We can instead check if 'a' is found. Once it is, we start another for loop, printing every character after. This first sounds counter-productive: a for loop inside a for loop is generally less efficient. However, this is really one for loop, breaking out of the entire program when the inner loop is completed.

In some languages, there are built-in functions to greatly help readability of the code and make the solve intuitively easier. In the second, 'optimized' approach within the pseudocode, there is the `SUBSTRING` command that can be used. If this is not within a programming language, a for loop starting at the occurrence of 'a' and exiting the program once completed as mentioned earlier will achieve the same end result.

C++ has the `.substr()` command from the `string` library. Python has the built-in feature `[i:]`, where `i` here is the index where 'a' is found. Bash can use multiple string manipulations, including regex or parameter expansion. In the bash solution submitted, I went with the latter. 

## Pseudo Code
Naive approach:
```
INPUT compString
bool found = FALSE

FOR s IN compString:
    IF found == TRUE:
        PRINT s
    ELSE:
        IF s == 'a':
            found = TRUE
```

Optimized approach:
```
INPUT compString

FOR i IN {0..LENGTH(compString) - 1}:
    IF compString[i] == 'a':
        PRINT SUBSTRING(i, LENGTH(compString) - 1)
        BREAK
```

## Time Complexity
Iterating through the entire string is time complexity $O(n)$. Even with the naive approach where there is an additional conditional check for each iteration, it still becomes $O(2n)=O(n)$. Since we can do no better than to iterate through the entirety of the string, this is also $\Omega(n) = \Theta(n)$.