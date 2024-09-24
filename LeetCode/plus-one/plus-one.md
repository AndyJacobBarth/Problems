# [Plus-One](https://leetcode.com/problems/plus-one)

This problem gives us a list of digits `digits`, representing one large number. We are asked to increment the number by one and output the updated list of digits. We know there are no leading $0$'s.

Initially, we may think we just need to increment the last digit by $1$:

```
digits[LENGTH(digits) - 1]++
```

This does not work for the case `digits[LENGTH(digits) - 1]` $= 9$. We will get a $10$ which is two digits, not one. Instead, we can set its value to $0$, and increment the digit before it by $1$. 

We may run into the same issue, that this digit may be a $9$, so we should iterate through `digits` while the current iteration still has value $9$.

What if the first digit is a $9$ during this check? We can set it to $0$ as we planned, but now we must insert a $1$ and push all the numbers back. Programming languages will usually accomodate memory for the first digit, so this does not mean moving every digit to different memory spaces. This is in fact the worst case scenario for us, which we'll describe under [Time Complexity](#time-complexity).

The constraints of this problem are that `digits.length` $\leq 100$ and each digit is from $0-9$, so our algorithm did not have to be efficient.

Can we do better? We will assess the time complexity in more detail below, but our algorithm is currently $O(n)$. If we only had to increment the last digit and didn't care if it was $9$, this would be $O(1)$ - accessing the last digit and adding $1$ both take constant time. Unfortunately, the $9$'s make this difficult. We do not know how many $9$'s are in the list, and we would need additional information that we don't have for how long the right-most string of $9$'s is. Attempting some sort of sorting method could give us the number of $9$'s and therefore an upper bound, but that would require a sorting algorithm that's guaranteed to be $< O(n)$. It's also clear that when there is no $9$'s, this just causes unnecessary overhead.

The code `RETURN` below refers to exiting out of the program.

## Pseudo Code
```
INPUT digits

iter = LENGTH(digits) - 1

WHILE digits[iter] == 9:
    digits[iter] = 0;
    
    IF iter == digits[0]:
        # Assumes function's arguments are the value to add and the index to push into, respectively
        digits.ADD(1, 0)

        PRINT digits
        RETURN

    iter--

digits[iter]++

PRINT digits
```

## Time Complexity
Getting an element in `digits` requires $O(1)$ time. The while loop in the best case does not execute. That is, when the last digit is not a $9$. We increment the last digit in $O(1)$ time, and print `digits`. If `digits` is copied, this would take $O(n)$ time for the $n$ digits. Programming languages may instead point to the existing `digits`, which would only take $O(1)$ time. The overall complexity is $\Omega(n)$ if `digits` is copied, and $\Omega(1)$ if pointed to.

If the digit being checked is a $9$, the while loop will execute. It has a fixed amount of conditional and arithmetic operations, so each loop takes $O(1)$ time. The worst case is a set of $n$ $9$'s. This will cause the while loop to execute $n$ times, resulting in an overall complexity of $O(n)$.