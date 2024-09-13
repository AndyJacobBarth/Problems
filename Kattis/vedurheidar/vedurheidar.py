v = int(input())
n = int(input())

while n > 0:
    s, k = input().split()
    k = int(k)

    if v > k:
        print(s + " lokud")
    else:
        print(s + " opin")
    n -= 1