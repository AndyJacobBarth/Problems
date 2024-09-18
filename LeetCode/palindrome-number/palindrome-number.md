# [Palindrome-number]("https://leetcode.com/problems/palindrome-number")

This problem asks us to return `TRUE` if the integer input $x$ is a palindrome number and `FALSE` otherwise.

It appears negative values are present, which are automatically not palindromes. We can convert the integer to a string and traverse from the end to the beginning, comparing chars. We default to assuming it is a palindrome, and return `FALSE` if we detect a discrepancy. Logically, we only need to check $\lfloor$ `LENGTH(x) / 2` $\rfloor$, where the floor operation is necessary in case the integer has odd digits, preventing us from redundantly checking whether the middle digit is equal to itself. In programming, this can be achieved by integer division.

The follow-up asks if we can perform this without converting into a string. It turns out converting to a string and doing string operations following is more intensive than if we maintain our operations at the integer level. I will be referring to the right-most digit as the Least Significant Digit, or LSD, akin to the binary Least Significant Bit (LSB).

We still check if $x < 0$ and return `FALSE` if this is the case. Then we can extract the LSD from $x$, save it to some variable `comparison`, shift $x$ one decimal place down, and shift `comparison` one place up. We repeat until we create a new number. This effectively reverses $x$, and we can compare if `x == comparison`. Since we need to compare $x$, at the end, we should store $x$ in some variable `temp` and do the manipulations on `temp`.

Extracting the LSD is accomplished by modulo $10$, but the modulus operator can be pretty expensive. A slight optimization is to do the following:

`comparison += temp - (temp / 10) * 10`

When `temp` is divided by $10$, this effectively shifts `temp` a decimal down. When we multiply by $10$, it shifts `temp` a decimal up, but now the one's place is set to $0$. We can then subtract this value from `temp` to extract the LSD. We've effectively created a base-$10$ bit mask (decimal-mask?) of the LSD.

The specifications for $x$ is exactly the limitations for a 32-bit signed integer, so we should use at least this data type when assigning $x$. Using integer manipulation can cause overflow if the integer is $9$ digits long and $x$ backwards is greater than $2^{31}-1$. We can use larger data types to accomodate for this, or unsigned data types since we already checked $x \geq 0$.

In the below pseudocode, `RETURN` is used to break out of the program and `//` denotes integer divison.

## Pseudo Code
Using string manipulation:
```
INPUT x

IF x < 0:
    RETURN FALSE

# Programming language may require conversion STR(X)
x_length = LENGTH(X)
middle = x_length // 2

FOR i IN {0..middle}:
    IF x[i] != x[x_length - 1 - i]:
        RETURN FALSE

# Only reached if no discrepancy is found
RETURN TRUE
```
Using integer manipulation:
```
INPUT x
IF x < 0:
    RETURN FALSE

temp = x, comparison = 0

WHILE temp > 0:
    comparison *= 10
    comparison += temp - (temp / 10) * 10
    temp //= 10
    
IF x == comparison:
    RETURN TRUE
RETURN FALSE
```

## Time Complexity
Converting $x$ to a string is considered $O(1)$ time. Iterating through $x$ from the ends and to the middle requires looping through $n / 2$ chars, with one comparison operation taking $O(1)$ time. The worst-case is therefore $O(n/2) = O(n)$. In the best case, either $x < 0$ or we find a mismatch early on, and these will take $\Omega(1)$.

In the integer manipulation, the manipulations upon `comparison` and `x` is $O(1)$ time. Looping through $x$'s digits requires $O(\log_{10}n) = O(\log n)$ time. The final comparison is considered to be $O(1)$ time, making the worst case $O(\log n)$. In the best case, as before, we will terminate when $x < 0$ in $\Omega(1)$ time.
