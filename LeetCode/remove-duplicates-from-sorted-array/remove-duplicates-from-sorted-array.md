# [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array)

This problem gives us a sorted array of integers `nums`and asks that we 

$(1)$ Have `nums` start with the subset of non-repeating integers, and

$(2)$ Return the number $k$ of non-repeating integers.

One interesting point to note is that the problem specifies it does not care what comes after the subset described in $(1)$. This hints that `nums` does not need to necessarily physical remove connections with duplicates and resize, which could create additional cost. The caveat is that $k$ indexes `nums`, so if $k$ is not correct, neither will the expected subset.

Counting $k$, the number of unique integers, may give us a start. Since `nums` is sorted, all the duplicates will be next to each other. We don't need to remember every unique integer we come across, we just need to compare consecutive integers. If they're the same, they're a duplicate. If different, we have a new unique number.

Another point to make is that the first integer in `nums` is always unique (technically, the last is too if we start there, but we will proceed wtih the first integer without loss of generality). We can leverage this to start indexing one after the first integer. Then for each iteration we compare `nums[i]` with `nums[i - 1]` at some index $i$.

Every time we come across a unique integer, we know that it's the next smallest unique number. We can take advantage that $k$ is incrementing per unique number to use it as an index for `nums`, and therefore `nums[k] = nums[i]`. In other words, when we come across a unique number at the $i^{th}$ index, we know this is the $k^{th}$ unique number. Before we update $k$, we can overwrite `nums[k]` to this unique integer, and then increment $k$.

Think of when we find our second unique integer (the first is always going to be at index $0$). This means that $k = 1$ initially, since we haven't counted the number yet. We established `nums[0]` will be our first unique number, so we have to add this new one to `nums[1]`. When we increment $k$ now, it becomes $2$, and this will set up for the index of the next unique integer we come across.

We don't have to worry about overwriting anything, because we are only overwriting at most as fast as we are checking, and the overwriting occurs after we are checking.

I have considered whether to exit early by looking ahead at the first and last index and seeing if they are the same. If they are, the entire array is a duplicate. This is a rare case and likely only a few test cases within the judge, so it's not worth considering. I have unsuccessfully attempted a recursive approach to this, similar to a binary search in the sense that you compare the index at different intervals to see if there are some indices you don't have to check. I will leave it as an exercise to the reader to see if they can come up with a solution this way.

One simple but less efficient solution is to use a set. Sets have no duplicates, so we can loop through `nums` and insert the values into a set `st`. With $k$ initialized to $0$, we can set `nums[k] = st[k]` and increment $k$ until the end of the set. This will have `nums` contain the subset of unique integers in the beginning and $k$ with the number of unique integers, as required.

## Pseudo Code
Set Solution:
```
INPUT nums

# Represents a set
st = {}

# Set will filter out duplicates and sort
FOR num IN nums:
    st.ADD(num)

FOR i IN {0..LENGTH(st) - 1}:
    nums[i] = st[i]
    k++

PRINT k
```
Optimized solution:
```
INPUT nums
i = 1, k = 1, nums_length = LENGTH(nums)

WHILE (i != nums_length):
    IF (nums[i] != nums[i - 1]):
        nums[k] = nums[i]
        k++
    
    i++

PRINT k
```

## Time Complexity
In the set solution, `nums` is looped through with $n$ elements. A set adding elements of `nums` to it can vary in time complexity, but we will assume $O(\log n)$ for each insertion, requiring $O(n \log n)$ time complexity within the loop. We assume $\log n$ in that the set can be represented as a binary tree, and adding elements in order would require $\log_2 n$ steps. Changing the first part of `nums` to match `st` requires $O(m)$ time, where $m$ is the number of unique integers ($k$ in the problem). The overall time complexity is therefore $O(n \log n + m)$.

In the optimized solution, We must iterate through `nums` once through each of the $n$ elements. The comparison, arithmetic, and substitution all take $O(1)$ time, so the loop takes $O(n)$ time overall. Since we must check every integer, this is exactly $\Omega(n) = \Theta(n)$.