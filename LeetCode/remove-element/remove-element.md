# [Remove Element](https://leetcode.com/problems/remove-element)

This problem gives us an array of numbers `nums` and a target value `val`. We want to count the number of instances of `val` in `nums` with a counter $k$, and alter `nums` such that it begins with all the numbers that are not `val`. We should return `k`.

This problem mentions that `nums` does not have to *only* contain the numbers not equal to `val`, only that it must start with those numbers. This strongly hints that we just need to move the values around, and we don't have to worry about removing elements within the list.

When we iterate through `nums`, we can check each number if it is `val`. If it isn't, we can increment $k$. That leaves only needing to place the number `nums[i]` to be placed in the beginning of `nums`.

This is actually fairly easy. We can initialize $k$ at $0$, and when we find a number not equal to `val`, we can leverage $k$ as an index for said number before incrementing $k$.

We're already done, but can we do better? Unfortunately, `nums` isn't sorted, and doing so would typically be $O(n \log n)$ time, which already takes longer than our first approach, which we break down in more detail below under [Time Complexity](#time-complexity). '

If you did proceed this way, you know `nums` contains the first $k$ numbers that aren't `val`, so that part is done. It's just a matter of finding $k$, which we can use a while loop to traverse linearly through `nums` until one of its elements is `val`, and exit, incrementing $k$ through each iteration except on the element we exit on. 

This would still take $O(n)$ time, and a faster search such as binary search would not work since we want the *first occurrence* of `val`, and there are potentially multiple elements we could hit with binary search that are not the first instance.

## Pseudo Code
```
INPUT nums, val
k = 0, nums_length = LENGTH(nums)

FOR i IN {0..nums_length - 1}:
    IF nums[i] != val:
        nums[k] = nums[i]
        k++

PRINT k
```

## Time Complexity
Since we loop through all elements in `nums`, and does not have any conditional exits otherwise, this algorithm is exactly $O(n) = \Omega(n) = \Theta(n)$.