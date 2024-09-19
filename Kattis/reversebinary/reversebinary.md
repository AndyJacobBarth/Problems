f# [Reverse Binary](https://open.kattis.com/problems/reversebinary)

This problem asks us to reverse a number $N$'s binary and print out the base- $10$ result.

If we take $N$ and modulate by $2$, we get the LSB, or Least Significant Bit (aka. the right-most bit). This When we divide by $2$, we can now take $N \mod 2$ again to receive the second right-most bit. We continue this process until we no longer have any more bits to receive, which is equivalent to if $N$ is $0$.

The reason why this works is more apparent when we do equivalent bitwise operations. Instead of taking $N \mod 2$, we can instead do `N & 1`, where `&` is the bitwise 'AND' operation. This is a bitmasking technique that allows us to receive the LSB. The following example illustrates this:

```
13 = 1101

  1101
& 0001
------
  0001
```
Performing `N & 1` ANDS every place with a $0$ except for the LSB, and `x & 0 = 0`, `x & 1 = x`, so therefore we get the LSB. We can save this value to use later.

Now when we divide by $2$, we are really shifting the bits right by $1$. We denote right shift as `>>`. The following is an example of `13 >> 1`:

```
1101
^^^

0110
 ^^^
```

Now the LSB is what was once the second-rightmost bit of $N$, and we desire this to be our second left-most bit, so we append this value to our first result. Then we shift right and bitmask again, repeating this until we get the result backwards. Here's the step-by-step process with $13$:

Bitmask LSB:
```
answer: 1
N:      1101
           ^
```

Shift right and bitmask new LSB:
```
answer: 10
N:      0110
           ^
```
Shift right and bitmask new LSB:
```
answer: 101
N:      0011
           ^
```
Shift right and bitmask new LSB:
```
answer: 1011
N:      0001
           ^
```
Shift right. $N = 0$ so we're done.
```
answer: 1011
N:      0000
```

Now that we have the reversed binary, we need to print this out in base- $10$. We can achieve this by iteratively multiplying the binary from right to left by progressive powers of $2$. This will give us our final answer. However, if right shift is division by $2$, we can do a left shift to multiply by $2$ and save some overhead.

In the below pseudocode, we combine all of these steps together. You may notice `answer` is left-shifted before receiving the LSB bitmask for $N$. This is intentional. If done after the bitmask operation, then when $N$ was $0$, `answer` would have been left-shifted one too many times, requiring a right-shift afterwards. (This becomes very problematic, as if we choose to hold `answer` with as many bits as `N`, we may lose a bit here). 

Instead, since `answer = 0` in the beginning, we can left-shift it first (`0 << 1` is `0`) so that `answer` is only further left-shifted when we know $N$ has more bits to output.

This is a surprisingly in-depth problem for how easy it's labeled. The implementation is not intuitive, as you have to carefully handle the output received. Some programming languages may convert to binary and back, which may make the problem easier. Python's `bin()` function can do this. If attempting to solve this optimally, it is better to manually extract the binary, as we can perform the steps mentioned above all in one iteration.

We should note that $N \leq 10^9$, which is just under a $32$-bit signed integer's max value:

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31} - 1 > 2 \times 10^9 > 10^9 = \max N$.

Since the bit manipulation we are doing keeps the result within this boundary, we don't need to worry about any overflow occurring.

## Pseudo Code
```
INPUT N
answer = 0

WHILE N > 0:
    answer <<= 1
    answer += N & 1
    N >>= 1

PRINT answer
```

## Time Complexity
Input and printing functions take $O(1)$ time. The loop shifts $N$ right by $1$ every iteration, which effectively divides $N$ by $2$. This loop therefore goes through $\log N$ iterations. The bitwise and right shift operations done on `answer` are done in $O(1)$ time within the loop. The worst-case scenario therefore takes $O(\log N) = O(\log n)$ time. If $N$ is already $0$, the best case scenario is that the program takes $\Omega(1)$ time.
