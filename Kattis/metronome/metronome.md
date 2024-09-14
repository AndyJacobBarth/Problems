# [Metronome](https://open.kattis.com/problems/metronome)

A metronome is used in this problem, giving $4$ ticks for every revolution of its key. Given the length of a song in $n$ ticks, we need to calculate the number of revolutions needed with the key.

This is more abstractly simplified to dividing the input by $4$. We need to be accurate by $2$ decimal places, which for virtually any floating point in a programming language should not be a concern.

Division by $4$ at a low-level for positive integers can be optimized by shifting the bits of the input right by $2$, denoted as $>>$, however with floating point numbers, this is not applicable.

There is no test case to consider, and as $n \leq 10^5$, we just need to be sure to use at least 32-bit signed integer, as this is an order of magnitude outside the range for 16-bit signed:

$2^{31} - 1 > 2 \times 10^9 > [10^5 = \max\{ n \}] > [2^{15} - 1 \sim 3 \times 10^4]$

## Pseudo Code
```
INPUT n
OUTPUT n / 4
```

## Time Complexity
Because we are doing one division operation, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.