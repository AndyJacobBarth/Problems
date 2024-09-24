# [Hissing Microphone](https://open.kattis.com/problems/hissingmicrophone)

This problem asks us to output `hiss` if a given string input has two consecutive s's, and `no hiss` otherwise.

There is no specifics mentioned for the string other than there are no spaces and length is at most $30$ characters. This means there is no guarantee the string is an actual word. We therefore must check every character if they are an 's'. If so, we check ahead if the next char is an 's', and output `hiss` and we're done. If not, we continue our search.

In other words, if we check char `comp_string[i]` and it's an s, we check `comp_string[i + 1]`. If `comp_string[i + 1]` is not an 's', we know we don't need to check it in the next iteration, and can skip over it.

There are no serious edge cases to consider, and the strings are short enough that no serious data types or structures need to be considered.

In the below pseudocode, `RETURN` refers to exiting the program.

## Pseudo Code
```
INPUT comp_string
comp_string_length = LENGTH(comp_string)
FOR i in {1..comp_string_length}:
    IF comp_string[i] == 's':
        IF comp_string[i + 1] == 's':
            PRINT "hiss"
            RETURN
        ELSE:
            i++
    
PRINT "no hiss"
RETURN
```

## Time Complexity
Our input and output are fixed and take $O(1)$ time. The for loop must loop through all $n$ chars of `comp_string`, since we have no information of where the s's are placed. The conditionals and arithmetic operations inside the loop all take $O(1)$ time, so the overall time complexity is $O(n)$, and because we can do no better as stated earlier, this will be $\Omega(n) = \Theta(n)$.