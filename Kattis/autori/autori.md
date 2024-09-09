# [Autori](https://open.kattis.com/problems/autori)

This problem wants us to take names concatenated with hyphens and shorten them to only the first letter of each name. The problem uses 'KMP' as an example, which is a reference to the KMP algorithm used for string searches. Fortunately, we don't need to get as involved into an algorithm as this.

The first letter will always be the start of our output, so we can either store this or directly print it if the programming language's print function does not automatically cause a line break.

We can then continue comparing chars until we find a hyphen (-). When one is found, we store/print the char after it. We then continue this process until we reach the end of the string.

It really should not get more complicated than that, since we are using a one character pattern match, and don't require to backtrack if we fail to find a match. An alternative method is to check if a character is its upper representation, but even if this feature is built-in to the programming language, it may have unexpected behavior for hyphens, and is generally more error prone. However, for Bash, I decided that this would be an easier alternative than the required regex to filter.

We are only expecting 100 ASCII characters, so there isn't anything extensive to consider. The problem specifies all hyphens are followed by an upper case letter, and otherwise all other letters are lowercase.

## Psuedo Code
```
INPUT names
shortened_names = names[0]
FOR i IN {1..LENGTH(names) - 1}:
    IF names[i] == '-':
        shortened_names += names[i + 1]
PRINT shortened_names
```

## Time Complexity
Since there is no backtracking for a mismatch, we only need to iterate through the string of length $n$. We also cannot do any better since we must check the entire string so this is complexity of $O(n) = \Omega(n) = \Theta(n)$.