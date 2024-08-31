# [Reduplikation](https://open.kattis.com/problems/reduplikation)

This problem gives us a string $s$ with characters a-z and a digit from $1$-$9$. It simply requests we print the string multiple times (as many times as the input digit is) in a contingent line (ie. no spacing or separation between strings).

This problem is pretty straightforward, only requiring a for loop printing the string no more than $9$ times. The biggest hurdle is knowing each programming language's formatting for such a task.

## Psuedo Code
```
INPUT s, digit
FROM 1..digit:
    PRINT s
```

## Time Complexity
Because this requires a for loop dictated by the input, this is of the order $O(n)$ for some input digit $n$. However, $n \leq 9$, so this complexity is written more academically than practically.
