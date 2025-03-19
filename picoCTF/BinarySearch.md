# Binary Search

When logging into this CTF, you have to guess a number between $1$ and $1000$. Optimally, we use binary search to guess the right number, hence the name of the problem.

We start with $500$. We will get a notice whether it is higher or lower, and we've reduced our options down to $500$. If we did any other number, there's a chance we could reduce the number of options, but a greater chance we increase the number of options. 

After our second guess of either $250$ or $750$, assuming we haven't hit the answer, we've now reduced our options to $250$. Continuing this, we see that we're constantly reducing our options by $\lfloor 1000 / 2^n \rfloor$ on our $n^{th}$ guess.

The program lets us have a maximum of $10$ guesses, so if we continue to use the binary search strategy, we will eventually hit 

$$
\lfloor 1000 / 2^{10} \rfloor = \lfloor \frac {1000}{1024} \rfloor = 0
$$

Meaning we've reached our answer. Note that the actual answer is random, so the solution actually depends on using the algorithm.