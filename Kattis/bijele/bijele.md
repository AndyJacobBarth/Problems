# [Bijele(https://open.kattis.com/problems/bijele)

This problem gives us, in order, the amount of:

kings, queens, rooks, bishops, knights, and pawns

that our protagonist Mirko currently has for his white chess pieces. He needs to know how many, if any, he needs to add or remove (represented as a negative number) in each respective group.

We know from the problem statement that the following are the numbers for the respective pieces Mirko should have:

1, 1, 2, 2, 2, 8

From here, we can subtract Mirko's numbers from these. If Mirko's piece count is greater than his expected piece count, $m_i > e_i$, we will get a negative number, identifying that he should remove pieces. If $m_i = e_i$, we return $0$, meaning nothing needs to be added or removed. Finally, for the case that $m_i < e_i$, we will end up with a postiive number, representing he should add more of those pieces.

Because each input $m_i \leq 10$, there are no edge cases to seriously consider.

Programming languages such as Python and Bash that read from a single line should interpret the full line as an integer array/list, which will look slightly different than the pseudocode provided.

## Pseudo Code
```
expected = [1, 1, 2, 2, 2, 8]

FOR i IN {0..5}:
    INPUT piece
    expected[i] -= piece

FOR i IN expected:
    PRINT i + " "
```

## Time Complexity
Our for loop is of fixed length of $6$, maintaining a time complexity of $O(6) = O(1)$. For each loop, we spend $O(1)$ time to read input, then $O(1)$ time to execute a subtraction operation.

This is followed by another for loop, again of fixed length $6$ ($O(1)$), and print out each element in this array, each in $O(1)$ time. Altogether, the time complexity is exactly $O(1) = \Omega(1) = \Theta(1)$.