# [Spritt](https://open.kattis.com/problems/spritt)

This problem gives us $n$ classrooms provided with $x$ sanitizer. We then have $n$ input, each indicating the amount of sanitizer required for each classroom $a_i$. We must print `Jebb` if we have enough sanitizer for all the classrooms, or `Neibb` otherwise.

Initially we may want to use a sum counter that adds up all the input, then compare the result with $x$. We can do slightly better by subtracting the inputs from $x$ and see if $x$ is greater than or equal to $0$, meaning we either had sanitizer to spare or we had exactly the amount of sanitizer needed for all classrooms.

It's important to note that $x \leq 10^8$ while $a_i \leq 10^8$. This means it's possible for a single classroom to already take up all our sanitizer. Since the number of input $n \leq 10^6$, it may benefit us to exit out of the loop early. We use `RETURN` in the pseudocode to represent exiting the program once we know all the sanitizer is used up.

The problem does specify that $\sum a_i \leq 2 \times 10^9$. This peculiar information is telling us that the problem expects us to use 32-bit signed integer, as 

$\max 32\_signed\_int = 2^{31}-1 > 2 \times 10^9$

and no data type larger is required.

For C++, adding I/O speed optimization by using `std::ios::sync_with_stdio()` and `std::cin.tie()` greatly help with the performance. Despite this, the current run time is $0.06s$. Bash exceeds time limit of $2.00s$ as well. I will leave it as an exercise to the reader how to improve on the algorithm and/or program-specific performance measures.

## Pseudo Code
```
INPUT n, x

WHILE n > 0:
    INPUT ai
    x -= ai
    IF x < 0:
        PRINT "Neibb"
        RETURN
    n--

PRINT "Jebb"
```

## Time Complexity
The initial reading of inputs $n, x$ is fixed and is only an $O(1)$ operation.

In the worst case, we must distribute sanitizer to all $n$ classes, making $n$ reads, $n$ comparisons, and $n$ subtraction operations (each independently taking $O(1)$ time). This results in $O(n)$.

In the best case, all the sanitizer is used up by $a_2$ (it's not possible for $a_1 > x$ as the problem specifies $\max a = \max x$). With our loop ending short at just $2$ inputs, this would give us our best case time complexity of $\Omega(1)$.