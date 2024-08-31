# [Ovissa](https://open.kattis.com/problems/ovissa)

This problem wants us to count the number of u's in the output. It seems safe to assume no other symbols will appear, as in the story, the input starts only when Unnar is uncertain, and Unnar only says the letter 'u' for a certain length of time when he's uncertain.

We can simply get the length of the string output.

## Psuedo Code
```
INPUT uncertainty
OUTPUT length(uncertainty)
```

## Time Complexity
Time complexity for the languages Python and C++ are $O(1) = \Omega(1) = \Theta(1)$. This is because the length of the string is stored when the string is input.

For Bash, this is not the case, and we have to iterate through every character to get the length. Therefore Bash is $O(n) = \Omega(n) = \Theta(n)$.