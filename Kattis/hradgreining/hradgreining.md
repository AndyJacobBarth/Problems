# [Hradgreining](https://open.kattis.com/problems/hradgreining)

We need to take a string and evaluate whether it contains the substring `COV`. If so, we output `Veikur!`, otherwise we output `Ekki Veikur!`.  

The constraints don't seem to matter here, as the output is at most 1000 characters.  Since it's printing out DNA, it should be safe to assume the characters are all capital.

We can iterate through the string until we find a 'C'. If a 'C' is found, we then check if the next char is an 'O'. If not, we iterate to the next char. If it is, we check if the third char is a 'V'. If so, we end here. Otherwise, we can iterate to the second next char (as the next char has been confirmed to be 'O'). It is not necessary to iterate through the last two chars, and this may even lead to errors if we're not careful.

There are multiple algorithms to find a pattern within a string. I've personally looked into detail in the KMP algorithm, with its time complexity described below.

The KMP algorithm looks at the search pattern and sees if characters in the beginning are repeated within the rest of the string. In more technical terms, it checks for suffixes that match the pattern's prefixes, and stores each character's 'longest prefix suffix', aka. a prefix table like this one for the string 'abac':

| a | b | a | c |
----|---|---|---|
| 0 | 0 | 1 | 0 |

For the purposes of this problem, I won't go much more in depth. Just think of it like this: Intuitively, if we came across the text 'ababac', the first four characters 'abab' are not a match to the pattern above, but 'aba' was. That second 'a' could be the start of the string we're looking for (and indeed it is), so the prefix table keeps track of possible ways the string we're looking for can start **within** the string we're checking.

The string it specifically asks us to check for is 'COV', which clearly has no matching prefix-suffix since each character in the pattern is unique. If we made a prefix table, it would be the following:

| C | O | V |
|---|---|---|
| 0 | 0 | 0 |

The pseudocode gives the entire KMP algorithm, with comments to identify specifics that we know about the pattern we're trying to search. Following this is pseudocode with the adjustments made.

C++ has the `.find()` command in the string library, with no find returning `std::string::npos`. Python has a built-in function for `.find()`, returning -1 if not found. Bash utilizes `[[ ]]`, syntax for pattern matching, for substring matches. Regex can also be used if the string is compared with the `=~` operator. It is left as an exercise to the reader to determine what algorithms are used for each.

## Psuedo Code
Basic iteration:
```
INPUT userInput
FOR (i = 0; i < length(userInput) - 2; i++):
    IF userInput[i] == 'C':
        IF userInput[i+1] == 'O':
            IF userInput[i+2] == 'V':
                PRINT "Veikur!"

                # Exit out of program
                RETURN
            ELSE:
                i += 2
        ELSE: 
            i++
    ELSE:
        i++

# If exited out of for loop but not out of the program, this will execute
PRINT "Ekki Veikur!"
```

Using built-in functions:
```
INPUT userInput

IF userInput CONTAINS "COV":
    OUTPUT "Veikur!"
ELSE:
    OUTPUT "Ekki Veikur!"
```

KMP Algorithm, returning `TRUE` if found:
```
INPUT text, pattern

# In this problem, lps = [0, 0, 0]
i = 0, len = 1, lps[LENGTH(pattern)]

WHILE (len < LENGTH(pattern)) {
    IF pattern[i] == pattern[len]:
        len++
        lps[i] = len
        i++
    ELSE:
        IF len != 0:
            len = lps[len - 1]
        ELSE:
            lps[i] = 0
            i++
}

i = 0, j = 0, found = FALSE
WHILE i < LENGTH(text):
    IF text[i] == pattern[j]:
        i++
        j++
    ELSE:
        IF j != 0:
            # This will always set j to 0
            j = lps[j - 1]
        ELSE:
            i++
    IF j == LENGTH(pattern):
        found = TRUE

IF found == TRUE:
    PRINT "Veikur!"
ELSE:
    PRINT "Ekki Veikur!"
```

Adjusted KMP Algorithm for this problem:
```
INPUT text, pattern

i = 0, j = 0, found = FALSE
WHILE i < LENGTH(text):
    IF text[i] == pattern[j]:
        i++
        j++
    ELSE:
        IF j != 0:
            j = 0
        ELSE:
            i++
    IF j == LENGTH(pattern):
        found = TRUE

IF found == TRUE:
    PRINT "Veikur!"
ELSE:
    PRINT "Ekki Veikur!"

```
Note that the first and last pseudocode examples are essentially the same. When j = 0 (no match), the KMP algorithm executes `i++` twice, effectively doing what the original code does when it executes `i += 2`. Instead of the variable j being used, the pattern is short enough to hardcode the iterations `i`, `i+1`, and `i+2`.

## Time Complexity
Iterating through the entire string of length $n$ and checking it against a pattern of length $m$ every time forces the algorithm into a complexity of $O(m \times n)$.

Utilizing the KMP algorithm, we iterate through the string of length $n$ without going back, while checking our pattern. Because we are not rechecking the instances where we've guaranteed a match, we are iterating through the text and pattern at complexity $O(n)$.  

If you lookup the complexity of the KMP algorithm, you may find that it is $O(n+m)$. However, this is due to having to make the prefix table in $m$ time. Since we have a fixed search string, and one that has a prefix table of all 0's, this complexity is reduced to $O(n)$.