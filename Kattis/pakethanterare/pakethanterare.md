# [Packagemanager](https://open.kattis.com/problems/pakethanterare)

This problem is horribly worded off the bat. To make sense of it, we're given the context that this has to do with packaging. The first line consists of the number of package types $t$ and the number of stores $b$. The next line has $b$ numbers that each describe the number of package types available for each store. The next $t$ lines contain a string describing the package type, and its maximum version number $v$. 

The remaining input is dependent on the second line of input which had $b$ numbers. That is, the remaining input is the package type each one contains followed by the current version number it's at. We want to output the total version difference of all package types for each store.

With all that being said, let's start our program. We want to read $t$ and $b$ on the first line. Then we want to read the next $b$ numbers on the second line. Each of these numbers will be less than or equal to $t$, since a store logically cannot have more package types than what exists. We have more input that follows, so we should store these values in a data structure of length $b$, like a list or array. We will call this `stores`, and conceptually this holds the number of all package types of each store.

We should then read the $t$ input containing a package type and version $v$. These are the most current versions of all the available package types, so we should store these for a baseline. We can use a **hash map** to create key-value pairs matching the package type with their respective current versions. All this means is that we create an efficient mapping system that we can later reference as a lookup table when we want to know a package type's most current reference. In our pseudocode, this is called `currentVersion`.

Now we can loop through the rest of the input. This consists of each of the $b$ stores, with the $i^{th}$ store containing `stores[i]` input defining which package types it has and what versions they're currently on.

Remember that our end goal is to find the total version differences of all package types for each store. We can start each store with having no version differences by creating a variable, say `versionDifference`, and setting it to $0$. When we iterate through the package types and their respective versions for each store, we look up the package type within our hashmap `currentVersion` and subtract this from what version the store has. We add this to our accumulator `versionDifference` for every package type the store has. When we are finished iterating through a store, we output the result and continue on.

That was a lot to go through, and explaining the problem was harder than the problem itself. It's recommended to follow the pseudocode to see what is going on more clearly.

As for constraints, We handle when the versions are all up-to-date, which is by defaulting `versionDifference` to $0$. We are given $t,b,v \leq 10^3$ and $t \times b \leq 10^6$, so it is recommended to use at least $32$-bit signed integers here, since

$32 \textunderscore signed \textunderscore int \textunderscore max = 2^{31}-1 > 2 \times 10^9 > 10^6 > 3 \times 10^4 \approx 2^{15}-1 = 16 \textunderscore signed \textunderscore int \textunderscore max$

Since $t \times b$ is never actually calculated, $16$-bit signed integer should also be okay here.

My fastest program in this is for C++ at $0.42s$ by adding `std::ios::sync_with_stdio()` to remove syncing with C and C++ and `std::cin.tie()` to remove tying `std::cin` and `std::cout` for better I/O performance. I was not able to make a Bash program that didn't exceed the time limit.

## Pseudo Code
```
INPUT t, b
stores = []

# Represents a hash map
currentVersion = {}

FOR i IN {0..b - 1}:
    INPUT stores[i]

FOR i IN {0..t - 1}:
    INPUT packageType, v
    currentVersion[packageType] = v

FOR store IN stores:
    versionDifference = 0

    FOR j IN {0..store - 1}:
        INPUT packageType, v

        versionDifference += currentVersion[packageType] - v

    PRINT versionDifference
```

## Time Complexity
Storing $b$ numbers in `stores` is $O(b) = O(n)$. Storing each package type in the hash map takes $O(t) = O(m)$ time. the final loop iterates through $b$ stores and checkes no more than $t$ package types per store, which is on the order of $O(t) = O(m)$. This makes the loop overall $O(n \times m)$, and therefore the total complexity of the algorithm is $O(n \times m)$. 