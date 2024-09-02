# [Aleidibio](https://open.kattis.com/problems/aleidibio)

This problem gives us minutes to go from Hannes to Arnar, then Arnar to the cinema. A third input is given, which is the minute of the day of the film's start that Hannes and Arnar want to go to. The output is essentially the maximum remaining time they will have before the film's start if they left immediately.  

This is a basic math word problem, where we just subtract the film start with the sum of the time it takes for our two heros to travel. That is, the output is  
(time before film's start: $c$) $-$ (time from Hannes to Arnar: $a$) $-$ (time from Arnar to film: $b$).  

There is no need to consider edge cases. In fact,  
$1 \leq a, b \leq 100$ and $720 \leq c$,  
so even  
$\min\{c\} - \max\{a\} - \max\{b\} \gt 0$.

## Psuedo Code
```
INPUT a, b, c

PRINT(c - a - b)
```

## Time Complexity
Because we are only doing two subtraction operations, the time complexity is constant, or $O(1) = \Omega(1) = \Theta(1)$.
