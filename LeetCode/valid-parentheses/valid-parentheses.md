# [Valid-Parentheses](https://leetcode.com/problems/valid-parentheses)

In this problem, we have a string of parentheses, square brackets, and curly brackets, referred together as brackets. We must ensure an open bracket must have a corresponding close bracket within the string. The same must be true vice versa, meaning we don't want any stray close brackets. Furthermore, they must be closed in a closed order. That is, the last open bracket must be closed before we can close any other bracket. If any of this is untrue, we return `FALSE`, but if all conditions are met, we return `TRUE`.

By describing the problem, it may be obvious that a stack is needed. If not, we will clarify this idea later. To start, let's ignore that there are different types of brackets and just consider parentheses `()`. 

Since there can be a rogue parenthesis anywhere, trying to be cheeky and start in the middle won't do us much good. Let's carefully consider whether there may be properties advantageous to us given that a string is valid. Initially, there may seem to require some symmetry, and we could tackle the string within the middle. Below is a counterargument:

<div style="text-align: center">

```
()(())
```

</div>

The string is valid, yet evidently it is not symmetrical. We can infer, however, that a valid string must be even in length. That is because every open bracket must have exactly one closing bracket to pair with it. Furthermore, a string must be at least of length $2$. This may help quickly eliminate some test cases.

One other property that may be worth mentioning is that if we were to count open and closed parentheses, say `i` and `j`, respectively, then if at any point `j` > `i`, we can be certain to exit early while returning `FALSE`, at least when iterating from left to right. This is a consequence of a rogue parenthesis appearing. The potential problem is that for a valid string, this would only add overhead, with at most $6$ comparisons for each char (one for each bracket side and type). Because we are able to answer this problem in efficient time without this, it is omitted from our final implementation.

Now, we can approach the string of parentheses either from the start or the end, it does not matter. Without loss of generality, we will consider from the start. The first char must certainly be `(`, otherwise we immediately return `FALSE`. The next char can be a `)`, but let's entertain the idea the next char is `(`. How should we remember that we need the first `(` to close? We can count the number of `(`'s in some kind of accumulator, and subtract from this accumulator when a `)` is present. In this way, we know that if the accumulator is ever negative, we can return `FALSE`. This logic comes from the idea that we have reached a rogue parenthesis, as mentioned in the previous paragraph. If the accumulator is not $0$ and is not negative, we have more `(` than `)`.

What happens when we now consider the different brackets? If we try the same method with a different count between different bracket types, we come across an error. Consider the following:

<div style="text-align: center">

```
([)]
```

</div>

This is invalid, because the square brackets must terminate before the parentheses. However, if we depended on our count, we have the right number of opened and closed brackets for each bracket type, so we would see no issue.

Counting was not in vein. It gave us the idea that we need to do some operation when an open bracket is present, and do an opposite operation when a corresponding bracket appears. We run into issues because the *last* bracket type that appears must be the *first* one to terminate. This is the concept of Last-In First-Out (LIFO), typical of a stack data structure. Like counting, we can **push** a bracket into a stack and **pop** the bracket when its corresponding end bracket appears.

How do we know what bracket to look for? We can use a key-value hash map. When an open bracket is placed in the stack, we can use a hash map that maps open and closing brackets to the same bracket type. If a closed bracket is detected but it does not map to the top of the stack's bracket, we know the string has become invalid and we can return `FALSE`. If the stack is empty when a closed bracket is detected, we can return `FALSE` as well, similar to when we used the counting method and the accumulator would turn negative. Much like when we need the accumulator to be $0$ at the end of our string, we need the stack to be empty.

Slight modifications to this can be done. Recall that I mentioned this was without loss of generality, so we could start at the end and add closed brackets to our stack while popping when the corresponding open bracket appeared, but there's really no reason to do it this way. Instead of a hash map, a string of opened brackets and a string of closed brackets would suffice if we iterate through them to compare. We just need to be sure that the indexing for these strings correspond to the same bracket type. Because they are only of length $3$, there is no noticeable performance difference. While we do not illustrate this in the pseudocode, the below would an appropriate initialization:

```
open_brackets = "([{"
close_brackets = ")]}"
```

Note that `(` aligns with `)`, `[` with `]`, and `{` with `}`. We can leverage these strings as a mapping between opened and closed brackets. In this way, the stack can retain the index in `open_brackets` of the opened bracket it comes across, and pop this value if the closing bracket matches this index in `close_brackets`.

The only constraint is that `s.length` $\leq 10^4$. A $16$-bit signed integer would be able to iterate through $s$, but this isn't even necessary as a for/in loop is used in our implementation.

## Pseudo Code
```
INPUT s

brackets {
    '(': ')',
    '[', ']',
    '{', '}'
}

# Represents stack initialization; cannot easily represent
stk = STACK()

FOR bracket IN s:
    IF bracket == '(' OR bracket == '[' OR bracket == '{':
        stk.PUSH(bracket)
    ELSE:
        IF stk.EMPTY() OR bracket != brackets[stk.TOP()]:
            PRINT FALSE
            RETURN
        
        stk.POP()

IF stk.IS_EMPTY():
    PRINT TRUE
ELSE:
    PRINT FALSE
```

## Time Complexity
The for loop iterates through all $n$ characters of `s`. Inside the for loop is a fixed amount of conditionals and stack operations, each taking $O(1)$ time. If a rogue bracket is found early, the for loop will terminate in $\Omega(1)$ time, representing the best case. In the worst case, we would have looped through the entire string in $O(n)$ time.