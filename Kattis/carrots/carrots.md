# [Carrots](https://open.kattis.com/problems/carrots)

This problem gives us a number of contestants $N$ and the number of 'huffle-puff' problems $P$ that they solve. The following $N$ lines are descriptions about each contestant. We are wanting to output the number of carrots that will be handed out.

Some extra context given in the problem is that a carrot is received after each huffle-puff problem is solved. So in fact, we only need to output $P$, and effectively all the other output is useless to us.

We can read and ignore the input for $N$, read $P$ to then immediately output, and ignore the remaining input. We can completely optimize by not even saving $N$ as a variable in our program.

$1 \leq N, P \leq 1000$, so there are no serious edge cases to consider.

## Pseudo Code
```
INPUT N, P

PRINT P
```

## Time Complexity
We first read $N$ in $O(1)$ time, then $P$ also in $O(1)$ time. Printing out $P$ is $O(1)$ time, resulting in a total time complexity of $O(1) = \Omega(1) = \Theta(1)$.

Note that we are not interpeting the $N$ input that follows, which otherwise would lead to our program running in $O(N) \sim O(n)$ time.
