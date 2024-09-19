# [Digitswap](https://open.kattis.com/problems/digitswap)

This problem asks us to swap a $2$-digit number, which we'll call $d$.

If we interpret the input as a string, we can reliably output the second digit, then the first.

If we interpret the result as an integer, we can get the digit in the one's place by calculating $d \mod 10$ and returning the result. If we integer divide $d$ by $10$, we will be left with the digit in the $10$'s place, which we can then output.

The modulus operator is denoted as `%`. We can alternatively compute $d - [d / 10] * 10$, where $[x]$ is the integer part of $x$. This can be achieved using integer division, denoted as `//`. This works because we truncate the one's place when performing $[d / 10]$, so multiplying by $10$ gives us $d$ but without its one's place digit. In the pseudocode, we simply just use the modulus operator.

Because of the limited possible inputs, there are no serious edge cases or data types to consider.

Experimentally, it appears that interpreting the input as a string is more efficient. I will leave this as an exercise to the reader as to why that is.

## Pseudo Code
Interpreting $d$ as a string:
```
INPUT d

PRINT d[1] + d[0]
```

Interpreting $d$ as an integer:
```
INPUT d

first_digit = d % 10 * 10
d //= 10

PRINT first_digit + d
```

## Time Complexity
Both algorithms rely on reading one input, printing one output, and using either concatenation and arithmetic operations. All of these operations are $O(1)$, and so both programs are $O(1) = \Omega(1) = \Theta(1)$.