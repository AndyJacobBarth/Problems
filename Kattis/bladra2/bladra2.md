# [Bladra 2](https://open.kattis.com/problems/bladra2)

This is a problem giving us inputs $v, a,$ and $t$ as velocity, acceleration, and time, respectively, for a balloon traveling upwards. We must solve for the distance $d$ it travels, which has the following formula:

$d = vt + \frac 12 at^2$

We can take the inputs and directly calculate the output using this formula. For most programming languages, using a built-in power function can be costly, and it's better to perform $t \times t$. Alternatively, we can use the distributive property to make this $t(v + \frac 12 at)$ for one less multiplication operation. $\frac 12$ should be hardcoded as $0.5$ to avoid an unecessary division operation.

We are given that $v$ and $a$ can be negative, but it should be safe to assume that the input will make logical sense, and we should always get a positive $d$. We can still allow negative values for $d$ as long as we use a 32-bit signed integer. This is because  

$\max\{vt + \frac 12 at^2\} ~ = (10^3)(10^3) + (10^3)(10^3)^2 = 10^6 + 10^9 \sim 10^9$

and 32-bit signed two's complement allows max positive integer $2^{31}-1 \gt 2 \times 10^9 > 10^6 + 10^9 = \max\{vt + \frac 12 at^2\}$.

Precision for this problem is required to be $10^{-5}$, which is odd since the input is all integers and the addition/multiplication operation stay within the field of integers.  The only floating point operation is multiplication of $0.5$, which is $2^{-1}$, and therefore requires at most precision of $2^{-1}$, or one decimal place in binary. This means we will always get accurate results by requiring only $10^{-1}$ precision. Regardless, as long as you're supporting some form of floating point, your solution should work.

As a side note, for Bash, floating point is usually supported with `bc -l`, but attempting this resulted in a runtime error. I suspect this command is not supported for judging, but using `awk` works well. For C++ and Python, floating point is invoked once multiplying by $0.5$.

## Psuedo Code
```
INPUT v, a, t
OUTPUT t*(v + 1/2 * a * t)
```

## Time Complexity
Because there are a fixed amount of four multiplication operations and one addition, this is $O(1) = \Omega(1) = \Theta(1)$.