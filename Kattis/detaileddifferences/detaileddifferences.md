# [Detaileddifferences](https://open.kattis.com/problems/detaileddifferences)

This problem gives us an integer $n$ representing the number of following input. There is actually $2n$ following input, as we are given a pair of strings that we need to illustrate the difference between. The strings then must be output, with `*` below a char to denote where the strings differ and `.` below a char to denote where the strings are the same.

We can simply iterate between both strings at once and compare the chars. If the same, we output `.` and if different, we output `*`.

Since we no longer use $n$ other than to gather the amount of following input, we can use it as an iterator in a while loop.

We are given that the strings are the same length, and that they are no greater than $50$ chars, so there are no serious limitations to consider.

## Pseudo Code
```
INPUT n

WHILE n > 0:
    INPUT s1, s2
    s1_length = LENGTH(s1)

    PRINT s1, s2

    # Assumes no new line created after PRINT executes
    FOR i IN {1..s1_length}:
        IF s1[i] == s2[i]:
            PRINT "."
        ELSE:
            PRINT "*"
    n--
```

## Time Complexity
We must read $2n$ input, making our read operations take a total time of $O(2n) = O(n)$. Since we need to compare every char in each string, we can do no better than iterate through $m$ chars, resulting in a time of $O(m)$. These two operations combined results in a time complexity of $O(n + m)$. Since we can do no better than read $n$ input and iterate through $m$ chars, this is also $\Omega(n + m) = \Theta(n + m)$.