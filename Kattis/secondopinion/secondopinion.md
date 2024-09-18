# [Secondopinion]("https://open.kattis.com/problems/secondopinion")

This problem gives us a number of seconds $s$ and asks us to output time in the format `HH : MM : SS`. The sample output suggest that there should be no leading 0's, although this is not specified.

The problem suggests to use integer division and the modulo operator. We will keep this in mind.

Some useful fast conversions is that $1 h = 3600 s$ and $1 min = 60 s$. We can first integer divide $s$ by $3600$ to get `hours`. We could use the modulo operator to get the remaining seconds as the problem suggests, but a better method would be to just subtract `hours * 3600` from $s$ to get the remaining seconds. The modulus operator is expensive, and subtraction/multiplication is generally considered faster. Regardless, there shouldn't be much noticeable performance difference either way.

We can repeat this process for minutes, where we integer divide $n$ by $60$ to get `minutes`. Subtract `minutes * 60` from $s$ to get the remaining seconds, which we don't need to convert any further. We then output in the desired format.

We should note that $s \leq 10^6$. We must be sure to use at least 32-bit signed integer because of the following:

$\max 32 \textunderscore signed \textunderscore int = 2^{31} - 1 > 2 \times 10^9 > 10^6 > 3 \times 10^4 \sim \max 16 \textunderscore signed \textunderscore int$

In the below pseudocode, `//` represents integer division and `%` represents the modulo operator.

## Pseudo Code
Using modulus:
```
INPUT s

hours = s // 3600
s %= 3600
minutes = s // 60
s %= 60

PRINT hours + " : " + minutes + " : " + s
```
Using multiplication and subtraction:
```
INPUT s

hours = s // 3600
s -= 3600 * hours
minutes = s // 60
s -= 60 * minutes

PRINT hours + " : " + minutes + " : " + s
```

## Time Complexity
With only one input and one output, both operations take $O(1)$. Converting for hours and minutes are a fixed number of arithmetic operations in $O(1)$ time, so the total complexity is $O(1) = \Omega(1) = \Theta(1)$.