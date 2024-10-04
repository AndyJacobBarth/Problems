# [Ferskasta Jarmid](https://open.kattis.com/problems/ferskastajarmid)

This problem gives us an integer $n$ followed by $n$ lines of memes as strings, their 'controversial' factor, and their 'coolness' factor. Controversial and coolness factors combine to give the freshness factor. It isn't clarified how they are combined to give the freshness factor, but we must determine which meme provided has the highest freshness factor and output it. If memes have the same freshness factor, we must print them alphabetically.

The problem does specify that controversiality is the number of seconds that a meme circulates, and coolness is the attention per second a meme gets. Freshness is the total attention, so we can do the following:

$s \times attention/s = attention$

$Controversiality \times Coolness = Freshness$

We can iterate through the $n$ memes and compute their freshness score. These memes are not sorted alphabetically, or really by any memes, so we should iterate through them linearly. We won't be able to determine the 'freshest' meme(s) immediately, so we should store all of these memes and their freshness values. However, we can figure out the best freshness value. We start by assuming the best is $0$, then update it if a meme's freshness value is more than our current best. If a meme is less than our current best value, we don't need to store it.

Doing this will definitely give us the best freshness value, but does not guarantee elimination of all memes that don't have this value. We could have a list of memes with progressively higher freshness values, so none of them would be eliminated in our first iteration. In this sense, a 'best freshness' variable is not substantially improve the performance.

We can now sort the list and print the first meme with the best freshness score. During our sort, we can prioritize sorting by the freshness value first, then alphabetically second. This ensures that the meme we want to output is the first meme in our list.

Sorting is the trickiest part of this problem, at least to do it efficiently. With a list of pairs, the sort needs to be defined to handle how we want to sort them. This can be done using lambda calculus. Many programming languages support this. Without getting too in-depth, we essentially define that we want the freshness values compared in descending order, then the strings compared in ascending order. Python and C++ support lambda notation.

Bash has flexibility with sorting using the `sort` command, which can be specified with the `-k`, or key, argument. We can specify to sort the second field (`2,2`, the fresh metric) first numerically (`n`) in reversed order (`r`). We can then sort the first field (`1,1`, the meme name) lexicographically, which is the default setting. The list is then parsed to get only the first result.

## Pseudo Code
```
INPUT n
memes = []
bestScore = 0

WHILE n > 0:
    INPUT meme, contro, cool
    fresh = contro * cool

    IF bestScore <= fresh:
        bestScore = fresh
        memes.ADD((meme, fresh))

    n--

# Assumes a sort such as merge sort
# Prioritizes sorting by second value, then by first value
SORT(memes, second, first)

PRINT memes[0][0]
```

## Time Complexity
We loop through $n$ memes, which is $O(n)$ time. We then sort the memes, first by their integer part, then by their string part. Assuming the string length is not significant, this becomes $O(n \log n)$. Therefore the total complexity of this algorithm is $O(n \log n)$. Note that sorting twice is still $O(n \log n)$, and we can assume the best case for the sorting algorithm is equivalent, meaning the program overall also has complexity $\Omega(n \log n) = \Theta(n \log n)$.