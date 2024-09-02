# [Bestagjofin](https://open.kattis.com/problems/bestagjofin)

This problem gives us a number of guests $n$ followed by the list of guests with a name and integer determining how fun their gift is. We need to find the largest integer and return the guest's name.

We can make a dictionary of key-value pairs, established as guest and their fun gift metric. We can assume our first guest has the best metric. When we get the input for the next guest, we can compare them with our current best, and have them replace our best if their metric is higher. We can continue this process for each input.  

In the pseduo code example, we use a while loop instead of a for loop because $n$ is solely used to describe number of inputs. This is a common method, but a for loop can be used all the same with little-to-no performance differences depending on optimization by compilers, if the programming language uses one.

A fun fact about the test cases is that I initially submitted a solution that did not replace the best_metric variable, yet all cases still passed. This means the designer did not make a test case to check for this. Therefore all $26$ test cases happened to have the last person to have a fun metric greater than the first person to also have the largest fun metric of everyone, which is a remarkable oversight.

## Psuedo Code
```
# Get first first name and their metric
INPUT n, name, fun_metric
best_metric = fun_metric
best_name = name

WHILE n > 1:
    INPUT name, fun_metric
    IF fun_metric > best_metric:
        best_metric = fun_metric
        best_name = name
    n--
PRINT best_name
```

## Time Complexity
Because we must iterate through each of the $n$ guests, this is $O(n)$. We have no further information to omit checking any guests, so this complextiy is also $\Omega(n) = \Theta(n)$.