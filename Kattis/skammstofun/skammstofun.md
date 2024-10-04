# [Skammstofun](https://open.kattis.com/problems/skammstofun)

This problem gives us an integer $n$ followed by $n$ words that may or may not be capitalized. If the first letter of the word is capitalized, we append it to our final output.

We can check the first character of every word and see if it is capitalized. If it is, we print it out. If not, we ignore it.

Since $n$ is not used for any calculations, we can use it as an iterator to loop through all the words received.

$n \leq 50$, so there are no serious cases to consider. We need to be able to handle whitespace appropriately, as all the words are on a single line.

Checking for capitalization has some differences between languages. C++ can handle comparison of the ASCII representations, and so it's sufficient to compare whether the first char in a word is greater than or equal to `A` and less than or equal to `Z`. Python has the built-in `.isupper()` function. Bash can utilize regex using `=~ [A-Z]` on the first char of each word.

## Pseudo Code
```
INPUT n

WHILE n > 0:
    INPUT word

    # Assumes built-in function for checking whether letter is capitalized
    IF word[0] == CAPITAL(word[0]):
        # Assumes no new line made
        PRINT word[0]
    n--
```

## Time Complexity
We are looping through $n$ words, but only one character for each word. We must check every word, so this is exactly $O(n) = \Omega(n) = \Theta(n)$.