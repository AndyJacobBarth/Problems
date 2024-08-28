# [Storafmaeli](https://open.kattis.com/problems/storafmaeli)

This problem wants us to print `Jebb` if input is a multiple of 10 and `Neibb` otherwise.  

We could use the modulus function, but since this problem focuses on $mod10$, we can optimize this a bit further by treating the input as a string and checking if the last character is '0'. This optimization is not entirely necessary, as even the modulus method is still considered to run in constant time.

## Psuedo Code
Modulus method:
```
INPUT n
IF n % 10 == 0:
    OUTPUT "Jebb"
ELSE
    OUTPUT "Neibb"
```
String method:
```
INPUT n
IF n[length(n)] == '0':
    OUTPUT "Jebb"
ELSE
    OUTPUT "Neibb"
```

## Time Complexity
Both methods run at a constant time $O(1) = \Omega(1) = \Theta(1)$.