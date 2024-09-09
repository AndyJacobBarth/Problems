# [Jumbojavelin](https://open.kattis.com/problems/jumbojavelin)

This problem will give us a number $N$ followed by $N$ rod lengths $l_i$ that will be fused together. For each fusion, it will lose $1\ cm$ of length. Logically, this means the rod after fusing all pieces together will lose $N - 1\ cm$.

Our output should be the sum of all the input numbers, then subtracting $N - 1$. In fact, we can create the sum $-(N - 1) = 1 - N$ before adding the lengths of the rods. This allows us to also use $N$ to increment through the input without creating another variable, although this is optimization isn't that impactful.

 We know $N > 1$ from the problem, so we don't need to consider this edge case. The largest our sum can be is $N \times \max \{ l \} = 100 \times 50 = 5000$, so a 16-bit integer type or greater is sufficient ($2^{15}-1 > 3 \times 10^4 > 5 \times 10^3$)

## Psuedo Code
```
INPUT N
sum = 1 - N
WHILE N > 0:
    INPUT l
    sum += l
    N--
PRINT sum
```

## Time Complexity
Because we must iterate through $N (= n)$ input, this is inevitably $O(1) = \Omega(1) = \Theta(1)$.