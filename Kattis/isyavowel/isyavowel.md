# [Isyavowel]("https://open.kattis.com/problems/isyavowel")

This problem asks us to count the number of vowels in a strictly lowercase string, once assuming 'y' is not a vowel, and a second time assuming 'y' is a vowel.

We can create a set, or array, of chars that are what we identify as vowels - 'a', 'e', 'i', 'o', and 'u'. We can then iterate through each char in the string and compare it to one of these values. If it's a match, we add to two permanent counters $counter_1, counter_2$.

If we instead find it matches 'y', we can add this only to the second counter $counter_2$. We can alternatively have the second counter *only* count the number of 'y's to later output $counter_1 + counter_2$, but this is just preference and doesn't result in any noticeable optimization.

## Pseudo Code
```
INPUT compString
vowels = ['a', 'e', 'i', 'o', 'u']

count1 = count2 = 0

FOR char IN compString:
    FOR vowel IN vowels:
        IF char == vowel:
            count1++
            count2++
    IF char == 'y':
        count2++

PRINT count1 + " " + count2
```

## Time Complexity
As we iterate through the string and compare between a fixed number of vowels, then incrementing two counters, we maintain a time complexity of $O(n)$. Since we have no choice but to iteratet rhough the entire string, this is the best we can do, and is therefore also $\Omega(n) = \Theta(n)$.