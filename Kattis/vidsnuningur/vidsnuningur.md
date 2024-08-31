# [Vidsnuningur](https://open.kattis.com/problems/vidsnuningur)

This problem is asking us to reverse any given input up to 1,000 English letters and digits. 

We can treat this input as a string, which is an array of chars. Then we just have to print the last char to the first.

A slightly faster solution is to swap the first char with the last, second char with the second-to-last, and so forth. If the string is even, this will behave as expected. If the string is odd, the middle char will swap itself. This will still give expected output, but it would be better to simply check if we're comparing the same letter, and exit if so. This can be done by comparing the indices and seeing if they are equal or ensuring indices do not overlap.

There are built-in functions for C++ and Bash. C++'s `std::reverse(BidirIt first, BidirIt last)` from the algorithm library behaves to the faster solution described earlier. Bash can use the `rev` command, which the manual page does not specify what it does. A good homework exercise would be to use GDB to walk through it and see what algorithm it uses.

Python has some reverse utilities, and some sources have used `reversed()`, `slice()`, and `.join()`. The fastest and most straightforward method is to utilize the indexing utilities of Python arrays. We can iterate in reverse indexing by using `[::-1]`. 

## Psuedo Code
#### Iterating from end to start:
```
INPUT stringInput
FOR char IN stringInput FROM POSITION [stringInput end] TO [stringInput start]:
    PRINT char
```
#### Swapping chars:
```
INPUT stringInput
INT left = 0
INT right = [stringInput length] - 1

WHILE (left < right):
    SWAP stringInput[left], stringInput[right]
    left++
    right--

PRINT stringInput
```

## Time Complexity
There are two main methods described here. Reading each char from last to first will iterate once through n chars, requiring n operations. This is $O(n) = \Omega(n) = \Theta(n)$. Note that Big Omega is still on the order of $n$ because we must iterate through the string no matter what.

The second method is to loop through half of the n chars, swapping them with the other half. This iteration requires n/2 operations. While guaranteed more efficient, it is only so by a constant, so the time complexity is still evaluated as $O(n/2) = O(n) = \Omega(n) = \Theta(n)$.
