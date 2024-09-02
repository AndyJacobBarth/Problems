# [Hipp Hipp](https://open.kattis.com/problems/hipphipp)

The problem simply asks us to output 20 lines of `Hip hip hurra!`

The naive approach is to output this 20 times. It's more reasonable to use a for loop. Any attempts at cleverly using a while loop or some other form is not necessary.

## Pseudo code
```
FOR 20 iterations:
  PRINT "Hip hip hurra!"
``` 

## Time Complexity
While we are iterating in a for loop, it is on a fixed amount, with precisely 20 print operations. The time complexity is therefore $O(1) = \Omega(1) = \Theta(1)$.
