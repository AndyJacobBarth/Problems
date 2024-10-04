# [Kinahvisl](https://open.kattis.com/problems/kinahvisl)

This problem is about the whisper's game. It starts out with a word, which is our first input. As it is whispered around, it is susceptible to being changed. We assume that one character could be changed for every person the word has been passed around to. The problem's second input is another string of the same length, indicating that the first string changed after $N$ iterations of being passed around. We must output the minimum $N$ people this word would be passed around in the whisper's game for this to occur.

When we find that a char in the second string is different than the char in the first string, this would indicate a change from a round of the whisper's game. If we keep tabs with an accumulator, we can check until the last char of the strings and output the resulting accumulator. We can start this accumulator with $1$ since whispering the word must start with $1$ person.

We are told the length of the words may be up to $10^6$, so we should store the length of the string at least of $32$-bit signed integer if we choose to do so, since

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^6 > 3 \times 10^4 \approx 2^{15}-1 = 16 \textunderscore signed \textunderscore int \textunderscore max$

The C++ code utilizes `std::ios::sync_with_stdio()` and `std::cin.tie()` to optimize I/O performance by ignoring synching C and C++ code and tying `std::cin` with `std::cout` to perform at $0.01s$. Only Rust submissions have been known to run faster. It's left as an exercise to the reader how to not get time limit exceeded for Bash.

## Pseudo Code
```
INPUT startWord
INPUT endWord
total = 1

FOR i IN {0..LENGTH(startWord) - 1}:
    IF startWord[i] != endWord[i]:
        total++

PRINT total
```

## Time Complexity
We have to iterate through the length of the strings, but the strings are the same length, shortening our loop to be $O(n)$ for a string of $n$ length. Everything inside the loop is $O(1)$, and we must check every char, so this program is exactly $O(n) = \Omega(n) = \Theta(n)$.