# [Echoechoecho]("https://open.kattis.com/problems/echoechoecho")

This problem asks us to print the output three times with spaces on the same line. This problem is pretty straightforward, and even gives us ways to gather input for popular programming languages.

The input is only one word, up to $15$ characters. We just need to make sure any unexpected whitespace is not read, particularly with Python.

## Pseudo Code
```
INPUT word
FOR i IN {1..3}:
    PRINT word + " "
```

## Time Complexity
Because we are printing out exactly three times, this is time complexity of $O(1) = \Omega(1) = \Theta(1)$.