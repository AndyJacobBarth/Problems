# [Longest-common-prefix](https://leetcode.com/problems/longest-common-prefix)

This problem asks us to find the longest prefix that is common in an array of strings `strs`. For no matching prefix, we return an empty string `""`. We are also expecting input to only be English letters.

A 'prefix' refers to the beginning of a string. We should be checking strictly left-to-right, as there's no guarantee of any prefix match until the very first char is a match. We should not misinterpret this question as asking for the longest matching substring, which would be a harder question. Instead, we need to compare the first char of all strings, then the second, and so on.

That's really all there is to it. The implementation is more difficult than the design. We can use the first string we get as our basis. This is because we are guaranteed at least one string in `strs`, and if we find a mismatch at all with the first string, we can stop our search for the longest common prefix.

Looping through each char of the first string, We can then loop through all the other strings and compare the $i^{th}$ char of the first string with the same $i^{th}$ char of the other strings. If there is ever a mismatch, we output our saved longest common prefix and exit the program.

The first string may be longer than the others, so we should also check to see if the index of the char we're comparing is greater than a string we're comparing to. If so, we can get no longer prefix and we exit the program.

Assuming our index is not out of range and we've found a match for every string, we can then append this char to our longest common prefix, and continue our iterations. When one of the earlier mentioned conditions occur, or the first string has ended, we return our longest common prefix.

A somewhat more clever approach is to sort the strings lexicographically. Once we do so, we can then just compare the first and last string in `strs` starting from the first char. If there is a mismatch at all, we stop looking for the longest common prefix. If there is a match, we know it must be a match for every string in between *because* we sorted them lexicographically. We analyze these approaches in closer depth below.

The constraints of this problem reveal that the expected input is very low. Each string is no greater than length $200$, and we expect no more than $200$ strings to compare. We should consider  the case where we only have $1$ string, although if looping/sorting appropriately, this shouldn't run into issues. The conditions for a loop should not run more than the length of the size of `strs`. The same can be said when a given string has length $0$, as is possible given the constraints. The index compared should be strictly less than the size of the strings being compared.

This problem gives rise to the idea of the Trie data structure, but with ability to solve this problem in a simple manner, I will omit the discussion of Tries and save this for a time where the implementation is more appropriate. 

In the below pseudocode, `RETURN` refers to exiting the program.

## Pseudo Code
Checking prefix of every string with the first string:
```
INPUT strs
strs_length = LENGTH(strs)
lcp = ""
first_str_length = LENGTH(strs[0])

FOR i IN {0..first_str_length - 1}:
    FOR j IN {1..strs_length}:
        # Exceeded length of compared string
        IF i >= LENGTH(strs[j]):
            PRINT lcp
            RETURN
        
        # Mismatch
        IF strs[0][i] != strs[j][i]:
            PRINT lcp
            RETURN
    
    # Match
    lcp += strs[0][i]

PRINT lcp
```
Sorting strings, then comparing prefix of first and last strings:
```
INPUT strs

SORT(strs, 0, LENGTH(strs))

first_str = strs[0]
last_str = strs[LENGTH(strs)]
first_str_length = LENGTH(first_str)
last_str_length = LENGTH(last_str)

FOR i IN {0..first_str_length - 1}:
    # Exceeded length of last string
    IF i >= last_str_length:
        PRINT lcp
        RETURN

    # Mismatch
    IF first_str[i] != last_str[i]:
        PRINT lcp
        RETURN

PRINT lcp
RETURN
```

## Time Complexity
If we choose the first string as a basis and compare its chars with every other string, in the worst case, we have all $n$ strings matching of length $m$. The loop will necessarily go through all $m$ chars of all $n$ strings and compare them, result in a time complextiy of $O(n \times m)$. In the best case, we terminate early when the strings have a mismatch (or a string's length is exceeded), resulting in $\Omega(1)$ time.

In the event we sort the array of strings first, we would choose a sorting algorithm such as merge sort that would have time complexity of $O(n \log n)$, even in the best case scenario. We then check each $m$ chars until the end of the first or last string in `strs`. In the worst case, this would be $O(m)$, but if we find a mismatch early, this would be $\Omega(1)$ for looping through chars. Therefore, in the worst case, this would take $O(n \log n + m)$ time, and in the best case, it would take $\Omega(n \log n)$ time.

We can see that choosing between the algorithms requires comparing $n \times m$ with $n \log n + m$. If $n \approx m$, then

$n \times m$ &rarr; $n \times n = n^2$ \
$n \log n + m$ &rarr; $n \log n + n = n(\log n + 1)$

We see that the initial algorithm is roughly $O(n^2)$ and the sorting algorithm is approximately $O(n \log n)$, so the sorting algorithm is better. This is the concept that our string length is proportional to the number of strings.

If $n >> m$, the initial algorithm becomes dominantly $O(n)$ while the sorting algorithm becomes $O(n \log n)$, and hence our initial algorithm is better. This means for predictably short string lengths and a large input size, our initial algorithm is better.

If $n << m$, then both algorithms are better approximated as $O(m)$, and either algorithm could be used. This means that for sufficiently long strings where there isn't as many of them, either algorithm would provide similar results.

In this particular problem, we have no advanced information of the string that is input, and the constraints are the same for $n$ and $m$, so ultimately either algorithm can be used.
