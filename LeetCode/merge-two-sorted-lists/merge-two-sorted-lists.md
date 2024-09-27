# [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists)

This problem has extensive use of linked lists. We will go over this data structure in a moment. For now, we know there are two sorted lists `list1` and `list2`, and we want to merge them into one sorted list, returning the beginning of this new list.

To begin, a linked list is an abstract concept of nodes, where each node points to another in a linear fashion:

```
(_) --> (_) --> (_)
```

In this problem, we are given some properties about the linked lists. One is that the nodes have some sort of value `val`. This is just whatever number is contained within them, which we established is done in a sorted order:

```
(3) --> (4) --> (5)
```

The other property is that each node has a corresponding `next` node. Intuitively this is the node they're pointing to. In our above example, the `next` node for `(3)` is `(4)`.

Beyond this, the problem establishes how list nodes are defined. If initialized without any specifications, it will have a default `val` of $0$ and its `next` node is `NULL`, meaning it will not be pointing to anything. We should be careful with how we treat this. We can also initialize a list node with a `val` and `next` if we desire.

One property of linked lists is that as we traverse one, we can never go backwards. Remember that there is a `next` node, but not a `prev` (previous) node. It is common to save the starting node of a linked list, called the **head**, so we can reference the beginning if we need to. Sometimes we may even save the **tail**, or the node at the end of the list, but we won't worry about that in this problem.

When combining two linked lists into one, we need to be sure that at each point in our algorithm, every node can still be retrieved. I will use the example above to demonstrate what could happen if we're not careful.

Let's say we change the `next` node of `(3)` to `(5)`. Then the following happens:

```
(3) -/-> (4) --> (5)
---
(3) --> (5)
   (4) --^
```

Hopefully my ASCII art is not too terrible to illustrate what's going on. `(3)` and `(4)` both have the `next` node as `(5)`. That's not the problem though. The real problem is that nothing is pointing to `(4)` now. If we were traversing this list starting at `(3)`, and it now points to `(5)`, we will never reach `(4)`. If we have nothing to reference `(4)`, we can never retrieve it. This may sound silly right now, but becomes an issue that we will explore in more practical terms in this problem.

Now that we have a better sense of linked lists, we should tackle the problem. As a disclaimer, there's many ways to do this problem, so I will only go over the methodology that I tackled this.

By the constraints of the problem, we know one or both of the lists could potentially be empty (ie. the head is `NULL`). If we see `list1` is, then we can return whatever `list2` has and be done. After all, even if `list2` is empty, we would return `NULL` and that would be accurate. If `list1` is not `NULL`, we can check if `list2` is, and if so we can simply return whatever is in `list1` and be done.

Most of the test cases are probably not empty lists, so let's continue exploring what we want to do. One of the sample cases are given to us as follows:

```
list1: (1) --> (2) --> (4)
list2: (1) --> (3) --> (4)

Result: (1) --> (1) --> (2) --> (3) --> (4) --> (4)
```

We can achieve the result by doing the following to the two lists:

```
list1: (1) --> (2)     (4)
        ^       |       ^
        |       V       |
list2: (1)     (3) --> (4)
```

Again, forgive my ASCII art, but hopefully the idea is presented here. All we're doing is changing the `next` node for each of the nodes based on order. All we have to do is ask ourselves, "How do we do this?"

The way I approached this is by starting with the list with the smallest `val` for its first node, or head. That is, whatever our intial values are for `list1` and `list2`, I wanted the smallest `val` of the two to be the start of our list. We can call this `finalList`. If `list1`'s `val` is equal to  `list2`'s, we can choose either one. In the actual code I present, I decide to go with `list2` in that event. Here is what it looks like in the test case we analyzed earlier:

```
l1 --> (1) --> (2) --> (4)
l2 --> (1) --> (3) --> (4)
        ^
        fl
```

`l1` represents `list1`, `l2` represents `list2`, and `fl` represents `finalList`.

To clarify, `list1` and `list2` are being used to reference the lists each as a whole, but also to reference the first node of each list. This can be confusing to those not familiar with pointers or how linked lists actually work.

A key thing to note is that `list1` and `list2` point to the head of the linked list, and so if we attempt to iterate through the list using `list1` or `list2`, we no longer have something pointing to the beginning that we can reference to. Similarly, whichever list we have determined to be the start of our `finalList` should not be modified so that we can return this pointer.

So we have the start of our answer being `finalList`. Now, we need to compare `val`'s of `list1` and `list2` to see what our next nodes should be. We know `finalList` is the list whose head is the smallest `val` between the two, but we don't have any way to reference the other list. We have to make yet another pointer for the other list so that we can iterate through it, which I cleverly call `otherList`:

```
 ol
 V
(1) --> (2) --> (4)
(1) --> (3) --> (4)
 ^
 fl
```

Where `ol` is the `otherList` pointer. I've removed `l1` and `l2` representing the `list1` and `list2` pointers because we won't be using those any longer. We can't reliably determine whether we're starting with `list1` or `list2` in this implementation, so we can't use them as iterators.

Recall that we don't want to use `finalList` as an iterator since we want to reference this when we return our final answer, so we must make yet another linked list node pointer `iter` that can be used to iterate through `finalList`:

That makes $5$ pointers before we've even begun to do anything, so you may think this is overkill. In fact, a slight optimization is to just switch `l1` and `l2` if the head `val` of `l1` $>$ `l2`, and return `l1` at the end (it doesn't matter which list you return, as long as it's the smallest `val`). This would require some third pointer `temp` that will act as a temporary pointer to `l1` so that they can be swapped, and you still need some pointer `iter` to iterate through `l1` since you want to keep `l1` to return. All-in-all, you will have $4$ pointers this way, which isn't much better. I decided to keep my $5$ pointers since I believe the naming convention helps prevent confusion, and there is virtually no performance difference.

Finally on to the problem at hand. The conceptual notion of the implementation is not difficult, but I leave it to the pseudocode to show how this is done by the program. We start with `iter`, which is currently pointing at the first node we want to have in our final list:

```
 ol
 V
(1) --> (2) --> (4)
(1) --> (3) --> (4)
^ ^
fl iter
```

 If we look ahead to its `next` node, we can see its `val` and compare it to that of the first node in `otherList`. If that value is still less than or equal, we already have it as the `next` to `finalList`, and that's exactly what we want, so we iterate through to the `next` node and repeat the process. We can continue to do so until finally the `val` for `iter`'s `next` node is greater than `otherList`'s:
 
 ```
 ol
 V
(1) --> (2) --> (4)
(1) --> (3) --> (4)
^ ^      ^
fl iter  iter->next
```
 
 Here,  `ol->val < iter->next->val`, so we already hit our end of the road.

 Now we want to point `next` to `otherList`, and continue iterating on `otherList`'s `next` nodes until their `val` is greater than `iter`'s:
 
```
 ol
 V
(1) --> (2) --> (4)
 ^
 |
(1)     (3) --> (4)
^ ^      
fl iter
```

Remember the issue I presented in the beginning, where we could no longer reference a node? That's the problem we just reached here. In the above diagram, we cut our connection to `(3)` and by extension `(4)` in `iter`, so it is impossible to reference them any further. Before we make a change to `iter`'s `next`, we must make a pointer (yes, our $6^{th}$ one) `temp` so we can hold onto the reference for `(3)`:

```
 ol
 V
(1) --> (2) --> (4)
(1) --> (3) --> (4)
^ ^      ^
fl iter  temp
```

Now we can change `next` on `iter`:
```
 ol
 V
(1) --> (2) --> (4)
 ^
 |
(1)     (3) --> (4)
^ ^      ^
fl iter  temp
```
And finally set `iter = temp` (`temp` is no longer illustrated since we no longer use it):

```
 ol
 V
(1) --> (2) --> (4)
 ^
 |
(1)     (3) --> (4)
 ^       ^
 fl      iter
```

Well, now we can do exactly what we did with `iter` with `otherList`. That is, we keep comparing `otherList`'s `next`'s `val` to see if it is less than or equal to `iter`. If so, we iterate `otherList`:

```
ol       ol->next
 V       V
(1) --> (2) --> (4)
 ^
 |
(1)     (3) --> (4)
 ^       ^
 fl      iter
```

`otherList->next` is indeed less than `iter` here, so we iterate `otherList`:

```
         ol      ol->next
         V       V
(1) --> (2) --> (4)
 ^
 |
(1)     (3) --> (4)
 ^       ^
 fl      iter
```

If no longer less than or equal to `iter`'s `val`, we do the same switcharoo concept and go right back to `iter`:

```
         ol      temp
         V       V
(1) --> (2) --> (4)
 ^
 |
(1)     (3) --> (4)
 ^       ^
 fl      iter
```

We've made our `temp` pointer.

```
         ol      temp
         V       V
(1) --> (2)     (4)
 ^       |
 |       V
(1)     (3) --> (4)
 ^       ^
 fl      iter
```

We've set `otherList->next` to `iter`.

```
                 ol
                 V
(1) --> (2)     (4)
 ^       |
 |       V
(1)     (3) --> (4)
 ^       ^
 fl      iter
```

We've set `otherList = temp`.

```
                 ol
                 V
(1) --> (2)     (4)
 ^       |
 |       V
(1)     (3) --> (4)
 ^       ^       ^
 fl      iter    iter->next
```

We have now gone back to comparing along `iter`. We repeat this process until either `iter` or `otherList` is `NULL`. Notice at the end of our example that `iter`'s `next` is `NULL`: 

```
                 ol
                 V
(1) --> (2)     (4)
 ^       |
 |       V
(1)     (3) --> (4)
 ^               ^
 fl              iter
```

Obviously we can't compare `NULL`'s `val` to `otherList`'s `val`, and when this happens we should just point `iter`'s `next` to the remainder of `otherList`. This would also handle whenever a list is longer than another. The same should apply if we happen to reach this scenario with `iter`:

```
                 ol
                 V
(1) --> (2)     (4)
 ^       |       ^
 |       V       |
(1)     (3) --> (4)
 ^               ^
 fl              iter
```

We finally have the list that we desire, and `finalList` is still cozily sitting back at the first node, ready to be returned.

What are some other approaches to this problem? I have seen solutions where they iterate through the nodes in a much cleaner fashion, but didn't align with the intuition that I had tackling this problem. I've seen people move the elements of each list into other data structures like arrays, then tackle the problem in that data structure, and finally convert it back to a list node to return. Because of so many different ways, I decided to only share my approach for two reasons:

(1) It helps maintain the thought process that I had, with no major performance differences, and

(2) My approach is not copy + paste of other approaches, and makes this write-up more genuine and unique.

## Pseudo Code
```
INPUT list1, list2
IF list1 == NULL:
    PRINT list2
    RETURN
IF list2 == NULL:
    PRINT list1
    RETURN

IF list1->val < list2->val:
    finalList = list1
ELSE:
    finalList = list2

IF finalList == list1:
    otherList = list2
ELSE:
    otherList = list1

iter = finalList

WHILE iter != NULL AND otherList != NULL:
    WHILE iter->next != NULL AND iter->next->val <= otherList->val:
        iter = iter->next
    
    IF iter->next == NULL:
        iter->next = otherList
        PRINT finalList
        RETURN
    
    temp = iter->next
    iter->next = otherList
    iter = temp

    WHILE otherList->next != NULL AND otherList->next->val <= iter->val:
        otherList = otherList->next

    IF otherList->next == NULL:
        otherList->next = iter
        PRINT finalList
        RETURN
    
    temp = otherList->next
    otherList->next = iter
    otherList = temp

PRINT finalList
```

## Time Complexity
The while loops may make the approach confusing, but we are really just iterating through the lists one step at a time. Therefore, we are going through $n$ elements of `list1` and $m$ elements of `list2`, resulting in total time complexity of $O(n + m)$. A list that is `NULL` will return in $O(1)$ time, but ignoring these trivial cases, the best case would be when all elements in `list1` (without loss of generality) are less than or equal to all elements in `list2`, resulting in $\Omega(n)$.
