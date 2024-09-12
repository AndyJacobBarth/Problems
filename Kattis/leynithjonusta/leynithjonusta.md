# [Leynithjonusta]("https://open.kattis.com/problems/leynithjonusta")

This problem gives us emails that they wish to interpret without any spaces. We need to remove this whitespace.

We can do this parsing in several ways. One method is treating each string separated by whitespace as a unique input. We can then print this input, check for any more strings, and continue the process.

Another method is to take the entire line as input first, and use a programming language to filter out any whitespace. This involves more processing and is generally slower. In the pseudo-code, we illustrate the for loop that a programming language of this capability would typically have a built-in function for.

We are not strictly given any constraints, but the scoring does indicate that the input may be as much as $10^6. If we try to do a lot of I/O commands, it may actually be more costly in the first approach than the second. I personally had a lot of difficulty implementing the right C++ code to get a fast solution. In the [CSES Competitive Programming Handbook](https://cses.fi/book/book.pdf), it recommends the following code:

```
std::ios::sync_with_stdio(0);
std::cin.tie(0); 
```

This will remove syncing with C and C++ code, as well as untying `std::cin` and `std::cout`. This is noticeably faster, but I've only been able to reduce the final result to $0.01s$. I will leave it as an exercise to the reader to optimize the C++ code further.

## Pseudo Code
Method 1 (interpreting input without whitespace):
```
WHILE (INPUT strings):
    PRINT strings
```
Method 2 (reading entire line and removing whitespace after):
```
INPUT strings
FOR char IN strings:
    if char != ' ':
        PRINT char
```

## Time Complexity
Both methods presented must iterate through $n$ input. In the first method, where we treat each string separated by whitespace as new input, the worst case is that every character is separated, requiring us to read $n$ input.

In the second case, we must iterate through the entire string, removing whitespace along the way. The first method is comparatively faster based on the number of whitespace $m$. That is, the first case has complexity $O(n)$ whereas the second method has complexity $O(n+m)$ for $m$ whitespace. However, $0 \leq m \leq n$, so the worst case would only be where 

$O(n+m) = O(n + n) = O(2n) = O(n)$.

Therefore regardless of the method, the time complexity is precisely $O(n) = \Omega(n) = \Theta(n)$.