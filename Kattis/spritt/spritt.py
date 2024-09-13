import sys

n, x = input().split()

n = int(n)
x = int(x)

while n > 0:
    ai = int(input())
    x -= ai
    if x < 0:
        print("Neibb")
        sys.exit()
    n -= 1

print("Jebb")