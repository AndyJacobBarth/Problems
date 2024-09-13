# [Barcelona]("https://open.kattis.com/problems/barcelona")

In this problem, we receive the total number of luggage $n$ and Benni's, this problem's protagonist, bag id $k$. This is followed by the IDs of the $n$ luggage with IDs $a_1,a_2,...,a_n$. If his ID is first, we print `fyrst`, if second we print `naestfyrst`, and otherwise we print `i fyrst`, where `i` is the index at which Benni's ID is located.

We must iterate through the list until we find Benni's ID. We may be inclined to use a sorting algorithm followed by an optimized search algorithm, but the ordering of the IDs actually matter, so we must search from left to right one by one.

We can make special conditionals if Benni's ID falls within the $1^{st}$ or $2^{nd}$ index, since these have specific words associated with them. Following that, we can use an incrementing counter until we hit a match. We use if/else functionality and a break to prevent future computations if a match is found in the below pseudocode.

In the first conditional, since we know $1 \leq n$, we can already interpret $a_1$. If this is a match, we end the code. If it isn't a match, we know by the fact that Benni's ID must appear that there must exist an $a_2$. We check this case, and if there isn't a match here, then we can create a generalized for loop to iterate until we do find a match. Once a match is found, we can break out of the program.

We know that we must find a match, so we don't have to do any error handling. We also know the first instance we find is Benni's ID, since it was specified there are no duplicates.

For Python and Bash, input is inherently read as a full line, so some liberties were made in their code that does not accurately reflect what is done within the pseudocode. Essentially, the line is interpreted as a structure of integers, which we loop through and manually check for cases where Benni's ID is $1^{st}$ or $2^{nd}$ inside the loop.

For C++, the functions `std::ios::sync_with_stdio(0)` and `std::cin.tie(0)` were used to desync C and C++ code as well as untie `std::cin` with `std::cout` for improved I/O speeds. Removing this will otherwise result in the program terminating in $0.01s$.

The constraints hold that $k$ and $a_i$ can be negative, each of magnitude up to $10^9$, and $n \leq 10^5$. We need to make sure that we are at least using a 32-bit signed integer for these values, as the following inequality compares the data type values:

$|-2^{31}| > 2^{31} - 1 > 2 \times 10^9 > 10^9$

## Pseudo Code
```
INPUT n, k, a1

IF a1 == k:
    PRINT "fyrst"
ELSE:
    INPUT a2

    IF a2 == k:
        PRINT "naestfyrst"
    ELSE:
        FOR i IN {3..n}:
            INPUT a
            IF a == k:
                PRINT i + " fyrst"
                BREAK
```

## Time Complexity
In the worst case scenario, we may find that Benni's ID is the last ID we check, which involves $n$ comparisons, each of $O(1)$ complexity. This results in a total time complexity of $O(n)$ for the worst case. In the event Benni's ID is the first match, we only had to do one comparison, and the result is a time complexity of $\Omega(1)$.
