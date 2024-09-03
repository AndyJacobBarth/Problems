# [Tolvunarfraedingartelja](https://open.kattis.com/problems/tolvunarfraedingartelja)

This problem simply wants us to subtract one from the input provided. It's making somewhat of a joke on how computer scientists count indices of data structures starting at 0.  

The constraint states that $n \leq 10^9$. This isn't a concern for most integer data types, but we should make sure to have at least a 32-bit integer, as it can hold up to $2^{31}-1 \approx 2 \times 10^9$.

## Psuedo Code
```
INPUT n
OUTPUT n-1
```

## Time Complexity
Since this is one operation, the time complexity is $O(1) = \Omega(1) = \Theta(1)$.