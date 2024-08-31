# [Bergmal](https://open.kattis.com/problems/bergmal)

This question appears to just want us to output what has been input. The context of the question makes it appear it wanted us to line separate the text, but the sample input/output does not reflect this.

There is still a caveat to this. We need to print the entire line, ignoring whitespace and special characters. Python's `print()` function already does this, but C++'s `std::getline()` is required, as `std::cin` is sensitive to whitespace. Admittedly, I've had quite a bit of trouble with Bash, as I don't understand what wasn't being interpreted correctly after using `IFS=read -r` to ignore whitespace and escape characters, and wrapping the variable around quotes. What ended up working had ironically ended up being far shorter than any other program: `cat`.

## Psuedo Code
```
INPUT code
OUTPUT code
```

## Time Complexity
The time complexity of this is $O(1) = \Omega(1) = \Theta(1)$, as we are just outputting what has been input.