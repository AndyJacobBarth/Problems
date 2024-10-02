# [Hakkari](https://open.kattis.com/problems/hakkari)

This problem introduces minesweeper. We are given $n$ and $m$ that specifies an $n \times m$ minesweeper grid. Within the grid, bombs are designated as `*` and empty space is designated as `.`. We must output the number of total bombs $k$, followed by $k$ lines representing the row and column of each bomb location, respectively.

We can use $n$ and $m$ to iterate through the minesweeper matrix. We simply check whether a given spot is an `*`, representing a bomb. If so, we increment a counter for the total bombs. We also note the indices of the bomb that we found.

A big issue with this problem is that we must first output the number of total bombs before the bomb locations. This requires us to hold all bomb locations before printing them out. We can do so by saving every pair of bomb coordinates inside a list. 

This list must be dynamic, meaning it should be able to expand as needed. C++'s `std::vector` can do so. We can prevent multiple reallocations by pre-defining the maximum size of the vector using `.reserve()`. We also save the coordinates of each bomb in a `std::pair` structure, where the $x, y$ coordinates can be called by `.first` and `.second`, respectively. Python's tuples are more straightforward. In my Bash code, I treat the pair as a string that I directly output, which is an alternative for the other langauges as well.

It's stated that $n, m \leq 100$, so there are no serious constraints to consider. 

## Pseudo Code
```
INPUT n, m
numBombs = 0
bombLocations = []

FOR i IN {1..n}:
    INPUT row
        FOR J IN {1..m}:
            IF row[j - 1] == '*':
                numBombs++;
                bombLocations.ADD((i, j))

PRINT numBombs

FOR location IN bombLocations:
    PRINT location
```

## Time Complexity
The algorithm we designed must loop through all $n \times m$ characters of the ASCII minesweeper grid. The comparison and storage take $O(1)$ time, making this loop $O(n \times m)$. When outputting all values, the worst-case is that the entire grid is bombs, which would take $O(n \times m)$ time to print. If none of the grid was a bomb, this would be $\Omega(1)$, but the loop to search for bombs remains $O(n \times m)$, so the algorithm retains a complexity of $O(n \times m)$. Since we can do no better than loop through the grid, this is also $\Omega(n \times m) = \Theta(n \times m)$.

Normally, space complexity is not mentioned in my analysis, but I thought it should be mentioned here. Again, the worst-case scenario is when all coordinates have a bomb in the grid. That would require a pair to be saved for every bomb, which takes up $O(n \times m)$ space. When there are no bombs, this complexity reduces to $\Omega(1)$.