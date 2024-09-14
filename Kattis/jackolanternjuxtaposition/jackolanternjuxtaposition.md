# [Jack'o'Lantern Juxtaposition](https://open.kattis.com/problems/jackolanternjuxtaposition)

This problem asks us for all possible arrangements of a jack-o-lantern's eyes $N$, nose $T$, and mouth $M$, but can be more abstractly boiled down to multiplying all three inputs. This is because the arrangements of the jack-o-lantern are independent of each other, and therefore can be directly multiplied.

## Psuedo Code
```
INPUT N, T, M
OUTPUT N * T * M
```

## Time Complexity
Because we are doing two multiplication operations, this is fixed at $O(1) = \Omega(1) = \Theta(1)$.