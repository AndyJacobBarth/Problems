# [Keys, Phone, Wallet](https://open.kattis.com/problems/keysphonewallet)

This problem gives us $N$, referring to the number of following input. $N$ lines follow, each with a string of some item. We must check specifically if `phone`, `wallet`, and `keys` are contained within the list. If so, we print `ready`. If not, we print whichever ones are not in the list alphabetically. Everything on the list is unique and lowercase.

Evaluating $N$ will not do us much good, as we need to figure out what items exactly are missing. We can create a list of `keys`, `phone`, and `wallet` and check each string to see if it matches any of these values. If they do, we remove them from the list and continue. If they aren't on the list, we don't worry about them.

Since $N$ is not used any further, we can utilize it as an iterator to receive the other values by using it in a while loop.

There are no edge cases or constraints to consider. Small optimizations can be made, such as early exit of the for loop when an item is found as `keys`, `phone`, or `wallet`, but the maximum comparisons is only $3$, so this is not considered.

Attempting to solve this in Bash proved difficult. The solution was to use the `unset` command on the array, and while it removed the item and lowered the count, the indexing did not change. The solution was to continue to iterate through the same indexes regardless of the size of the array.

## Pseudo Code
```
INPUT N
inventory = ["keys", "phone", "wallet]

WHILE N > 0:
    INPUT item

    FOR i IN {0..LENGTH(inventory)}:
        IF item == inventory[i]:
            inventory[i].REMOVE()
    N--

IF inventory.ISEMPTY():
    PRINT "ready"
ELSE:
    FOR i IN {0..LENGTH(inventory)}:
        PRINT inventory[i]
```

## Time Complexity
The while loop goes through $N$ input, which we'll refer to as $n$. Each input is compared by a dynamic amount of elements in `inventory`, but no more than $3$ elements. Removing the element takes $O(1)$ time from `inventory`. Looping through inventory to output its contents takes no more than $O(3) = O(1)$ time as well, resulting in an overall complexity of exactly $O(n) = \Omega(n) = \Theta(n)$.