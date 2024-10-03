# [Maeting](https://open.kattis.com/problems/maeting)

We are given a list of attendance for students identified by number for Monday and Tuesday. Despite the problem stating we are interested in seeing what students attended both Monday and Wednesday, we are only given Monday and Tuesday. The problem would be impossible to solve. Instead, we should assume it's asking us to find out what students attended Monday and Tuesday. 

We are given $n$ and $m$. There are $n$ students that attended school Monday and $m$ students that attended school Tuesday. The list of students (identified by number) for Monday are given on the next line, and the list of students for Tuesday are on the following line. We must identify all students who attended both, in order as they appear on the Tuesday list.

The lists are not specified to be in order. The first student listed on Monday could be the last student listed on Tuesday. One approach is to save Monday's list. We then iterate through each student on Tuesday's list to find a match on Monday's list. If there is a match, we output that student, otherwise we don't. We could remove students from the list as we find them, but removal can be $O(n)$ complexity, which can add more harm than good to our algorithm, so we do not consider doing this here.

Another approach is to first sort the list for Monday and store it. We would not desire to sort Tuesday because we must output the students as they are currently ordered. Now when we iterate through the list on Tuesday, we can do a binary search for each student.

We are told that the student ID's $x \leq 10^5$, so we need to assign at least a $32$-bit signed integer, since

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^5 > 3 \times 10^4 \approx 2^{15}-1 = 16 \textunderscore signed \textunderscore int \textunderscore max$

We know the IDs for the students are unique by statement of the problem.

The below pseudocode uses `BREAK` to refer to exiting the inner-most loop.

## Pseudo Code
No sorting, linear search:
```
INPUT n, m
monday = []
tuesday = []

FOR i IN {0..LENGTH(n) - 1}:
    INPUT student
    monday[i] = student

FOR i IN {0..LENGTH(m) - 1}:
    INPUT student
    tuesday[i] = student

FOR i IN {0..LENGTH(n) - 1}:
    FOR j IN {0..LENGTH(m) - 1}:
        IF monday[i] == tuesday[j]:
            PRINT monday[i] 
            BREAK
```
Sorting before binary search:
```
INPUT n, m
monday = []
tuesday = []

FOR i IN {0..LENGTH(n) - 1}:
    INPUT student
    monday[i] = student

FOR i IN {0..LENGTH(m) - 1}:
    INPUT student
    tuesday[i] = student

# Assumes built-in function for sorting, e.g. Merge Sort
SORT(tuesday)

FOR i IN {0..LENGTH(n) - 1}:
    # Assumes built-in binary search returning bool
    found = SEARCH(tuesday, monday[i])

    IF found == TRUE:
        PRINT monday[i]
```

## Time Complexity
When there is no sorting involved, we first read $n$ input and storing into `monday`, taking $O(n)$ time. We then read $m$ input and store this into `tuesday`, taking $O(m)$ time. Gathering all the input altogether takes $O(n + m)$ time.

The key difference between the two approaches is unsorted linear search and sorted binary search. For linear search, we iterate through Tuesday's list for every student in Monday's list. The worst-case scenario is that none of the students on Monday's list is on Tuesday's list, looping through Tuesday's $m$ students for every $n$ of Monday's students, taking $O(n \times m)$ time. Since $n \times m > n + m$, this is the worst-case complexity of the entire algorithm.

In the best-case scenario, we assume that $n \leq m$ as otherwise there would be some students not on the list, exhausting our search. The first student on Monday's list is found on Tuesday's list immediately. The second student is found after just checking two students, as the first student was already matched. As we go through each student, we inevitably have to do $i$ checks for the $i^{th}$ student. The total number of searches for $m$ students is as follows:

$1 + 2 + 3 + ... + n = \frac {n(n+1)}2$

Which is on the order of $\Omega(n^2)$.

The overall best-case time complexity is $\Omega(n^2 + m)$ for the program, as $n^2 > n$ but we still need to establish the complexity to include $m$.

For the sorted binary search, the search is assumed to be a time complexity akin to merge sort such that it takes $O(m \log m)$ time. Then the $n$ students on Monday are checked through a binary search of Tuesday's list. In the worst case, this search is exhausted for every student, which takes $\log m$ time per student. The total complexity would therefore be $O(n \log m)$ for the full search. This is also the overall complexity of the program if the following holds true:

$n \log m > n + m$

$n(\log m - 1) > m$

$n > \frac m{\log m - 1}$

and the complextiy is $O(n + m)$ otherwise.

The best-case scenario is similar to the other approach. We shouldn't have students not in Tuesday's list, so we should have $n \leq m$. We can assume minimization of the search, so the first student would be found immediately, the second student found after two iterations, the third after three iterations, and so on:

$\log 1 + \log 2 + ... + \log n = \log (\prod_{i = 1}^ni) = \log (n!)$

The best case would therefore be $\Omega(\log (n!))$ for the full search. [Stirling's approximation](https://en.wikipedia.org/wiki/Stirling%27s_approximation) estimates this to be roughly $\Omega(n \log n)$. Combined this with the complexity of the read input, and the best-case complexity of the program becomes $\Omega(n \log n + m)$.

All this analysis shows that sorting in the worst and best-case scenario is better than without doing so.