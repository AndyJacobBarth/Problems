# [Two-Sum](https://leetcode.com/problems/two-sum)

This problem gives us an array of integers `nums` and an integer `target`. We must return the indices of two numbers in `nums` that sums to `target`, given that a solution exists and is unique.

Our first approach may be to iterate through each of the $n$ values in `nums`. We then compare this to the other $n - 1$ values and see if adding them results in `target`. We must take care to ignore the case when `i == j`, as we cannot use the same index as the solution.

We can optimize this slightly further by realizing we don't need to repeat checks. For iterators `i`, `j`, if we compare `nums[i] + nums[j] == target`, we don't need to compare `nums[j] + nums[i] == target`. The second pseudocode sample illustrates this improvement, but the order of complexity matches the first approach, as explained further below. Recall that the same index cannot be used more than once, so `j` starts to iterate at `i + 1`.

A third approach is to use a sort of some kind, preferably one that is $O(n \log n)$. Then for each $n$, we can use a binary search to find `target - nums[i]`. Once found, we return the index that we saved for both `nums[i]` and `target - nums[i]`. This is a considerable improvement over the previous approaches, but we can do better.

The best approach is to use a hash map. Let's first talk about an unoptimized method of using hash map, then evolve into the optimal approach. The below pseudocode will only consider the optimal approach. 

We can iterate through `nums` and give them a key-value correspondence inside a hash map. This is desirable because extracting from a hash map is $O(1)$ time. The key would be `nums[i]`, and the value would be `i`. We could iterate through `nums` once more to see whether `target - nums[i]` exists. If it does, we can output the hash map's corresponding values for `nums[i]` and `target - nums[i]`. If $2 \times$ `nums[i]` $=$ `target`, we would hit duplicates, so we would have to account for this. 

The optimization of this hash map method is to actively create the hash map as we iterate through `nums`. This is achievable by first calculating `target - nums[i]`. If this value exists in our hash map, we just need to print `nums[i]`'s index and the hash map's stored index for `target - nums[i]`. If it doesn't exist, we then add `nums[i]` and its index `i` to our key-value pair hash map. This inherently prevents us from retrieving duplicate indexing as our solution as well.

We know $2 \leq$ `nums.length` $\leq 10^4$, so we would like to use an algorithm of $O(n^2)$ or better. We also should note that `nums[i]` and `target` can be fairly large, up to $|10^9|$, so we should use at least 32-bit signed integers, since:

$32 \textunderscore SIGNED \textunderscore INT \textunderscore MAX = 2^{31}-1 > 2 \times 10^9 > 10^9$

The pseudocode below uses a `BREAK` indicator to halt the program when a solution is found.

## Pseudo Code
Naive approach:
```
INPUT nums, target
nums_length = LENGTH(nums)

FOR i IN {1..nums_length}:
    FOR j IN {1..nums_length}:
        IF (nums[i] + nums[j] == target) AND (i != j):
            PRINT [i, j]
            BREAK
```
Slight optimization by removing redundancy:
```
INPUT nums, target
nums_length = LENGTH(nums)

FOR i IN {1..nums_length}:
    # Change is here
    FOR j IN {(i + 1)..nums_length}:
        IF nums[i] + nums[j] == target:
            PRINT [i, j]
            BREAK
```
Using sort and search algorithms:
```
INPUT nums, target
nums_length = LENGTH(nums)

# Pair retains original index of nums
indexed_nums = []

FOR i IN {0..nums_length - 1}:
    indexed_nums[i] = (nums[i], i)

# Indicates sorting by first (0th indexed) element
SORT(indexed_nums, 0)

FOR i in {0..nums_length - 1}:
    num = indexed_nums[i].first
    complement = target - num

    # Returns index, assuming -1 if not found
    # Must also not start at i to avoid duplicate indexing
    match = SEARCH(indexed_nums, complement, START = i + 1)

    IF match != -1:
        PRINT [index_nums[i].second, indexed_nums[match].second]
        BREAK
```
Using hash map:
```
INPUT nums, target
nums_length = LENGTH(nums)
hash_map = {}

FOR i IN {0..nums_length - 1}:
    complement = target - nums[i]

    IF hash_map CONTAINS complement:
        PRINT [i, hash_map[complement]]
        BREAK
    ELSE:
        hash_map.ADD(nums[i], i)
```

## Time Complexity
In the first naive approach, we iterate among $n$ input in `nums`, adding it to the other $n - 1$ values and comparing to see if it equals `target`. The addition and comparison are of $O(1)$, and the iteration results in $O(n \times (n-1)) = O(n^2)$. In the best case, the solution occurs at `i = 1` and `j = 2`, resulting in $\Omega(1)$.

In the slightly more optimized approach where redundancy is removed, our iteration reduces to 

$(n - 1) + (n - 2) + ... + 2 + 1 = \frac {(n - 1)(n - 2)}2$

in the worst case. In other words, this becomes $O(\frac {(n-1)(n-2)}2) = O(n^2)$. This illustrates that while it is optimized, for large $n$, we will see roughly the same performance between the programs.

The third algorithm requires a bit more analysis. We first create a pair to retain the original indices of `nums`, which takes $O(n)$ time. We then sort this pairing, which we specified should be an algorithm like merge sort that would take $O(n \log n)$ time. Finally, we would iterate through the $n$ elements of `nums`, using a binary search that takes $O(\log n)$ time. We then output the desired indices which is $O(1)$ time.

In this case, the independent functions occurring in our program require us to analyze the worst case analysis. This would be our sorting algorithm, which is $O(n \log n)$. It happens that merge sort is exactly this complexity, so although binary search at the best case would take $\Omega(1)$, and we could modify the code to exit when the solution is found such that best case within the loop is $\Omega(1)$, the program as a whole maintains its best case is also restricted by merge sort's $n \log n$ time, resulting in overall complexity $O(n \log n) = \Omega(n \log n) = \Theta(n \log n)$.

The final approaches require using a hash map. As mentioned, retrieving from a hash map is $O(1)$. The unoptimized approach of first creating a key-value pair for every $n$ elements takes $O(n)$ time, then looping again to check against `target - nums[i]` takes $O(n)$ time, resulting in a complexity of $O(2n) = O(n)$.

The optimized approach of looping through `nums` requires $n$ iterations of checking the hash map in $O(1)$ time and adding to the hash map in $O(1)$ time if a result is not found. This results in a total complexity of $O(n)$. Should the answer be indices $0, 1$, the best-case scenario results in a time of $\Omega(1)$.