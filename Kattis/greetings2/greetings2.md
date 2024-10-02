# [Greetings!](https://open.kattis.com/problems/greetings2)

This problem gives us a string of the form `he..ey` and we need to print the string with twice as many `e`'s. This string is of length at least $3$, implying there is always at least one `e` in the input.

We know the first char is always `h`, so we don't have to analyze whether this is an `e`.  When we go to the second char, we can either check until we hit `y`, or check until the char is not `e`. Either would be equivalent.

If the programming language retains the length of a string, we know there are $n - 2$ `e`'s for a string of length $n$. We can print `h` followed by $2(n - 2)$ `e`'s followed by `y`, and be done. We only consider this case in our pseudocode.

If the programming language does not store the length of the string, we can iterate through the string to find its length and follow the previous algorithm. Alternatively, we start by outputting `h`, and start at index $1$ in the string. While the input is `e` (or until we reach `y`), we can output $2$ `e`'s. Then we output `y` at the end. Either way does not result in much performance difference.

We know the string is at most $1000$ length, so relatively inefficient methods will still result in fast times.

## Pseudo Code
```
INPUT hey
heyLength = LENGTH(hey)
PRINT 'h'

FOR i IN {1..heyLength - 2}:
    PRINT 'ee'

PRINT 'y'
```

## Time Complexity
We are printing $n - 2$ `e`'s, requiring a time of $O(n - 2) = O(n)$. Since this is required by the problem itself, we can do no better, and so this is also $\Omega(n) = \Theta(n)$.