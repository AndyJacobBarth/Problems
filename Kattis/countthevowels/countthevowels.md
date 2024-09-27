# [Count the Vowels](https://open.kattis.com/problems/countthevowels)

This problem asks us to count the number of vowels in a string $s$.

We can easily do this by containing our own string `vowels` containing a, e, i, o, and u in both upper and lower case. We can loop through `s` and check each char as to whether it's a vowel. If it is, we can have an accumulator `total` that will increment by $1$.

An alternative to storing upper case is to convert every char to lowercase. Many programming languages have built-in functions to do this. This may be more practical for pattern matching of unknown letters, but since our list is fairly small, we can just include the capital letters here.

The only concern is for spaces. Some programming languages will treat this as new input, but we want to treat the entire line as one string. For C++ specifically, we can use `std::getline()` to accomplish this.

## Pseudo Code
```
INPUT s
vowels = "aeiouAEIOU", total = 0

FOR char IN s:
    FOR vowel IN vowels:
        IF char == vowel:
            total++

PRINT total
```

## Time Complexity
We are looping through $n$ characters of `s` and comparing each one to $10$ vowels ($5$ uppercase and $5$ lowercase). Therefore the total time for this program is $O(10n) = O(n)$. Since we must iterate through all of the characters in our program, this is also exactly $\Omega(n) = \Theta(n)$.