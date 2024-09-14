# [Oddities]("https://open.kattis.com/problems/oddities")

In this problem, we are given $n$ input and must determine if they are even or odd.

A common technique for determining even or odd is by using modulo $2$ on the input. However, the modulus operator can be computationally expensive. Another approach is to observe that in binary, all odd numbers end in $1$, and all even numbers end in $0$. 

Knowing this, we can use the bitwise `&` (AND) operator against the input and $1$. This technique is called bitmasking, since it's a clever trick to extract the right-most bit (aka. LSB, or least significant bit). If the result is a $1$, we know the binary representation of the input ends in $1$, so it is odd. Otherwise, it is even.

Since $n$ is only used to tell us how much input there is, we can use it as a decrementer to traverse through the rest of the input $x$.

Because $n \leq 20$, and $-10 \leq x \leq 10$, there are no serious edge cases to consider.

## Pseudo Code
```
INPUT n

WHILE n > 0:
    INPUT x
    IF x & 1 == 1:
        PRINT x + " is odd"
    ELSE:
        PRINT x + " is even"
    n--
```

## Time Complexity
We are looping through $n$ input, doing a bitwise comparison taking $O(1)$ time and a print operation in $O(1)$ time. Therefore, the total time complexity is $O(n) = \Omega(n) = \Theta(n)$. However, $n \leq 20$, meaning we are only dealing with small input and the analysis is not significant here.