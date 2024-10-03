import bisect

n, m = map(int, input().split())

monday = list(map(int, input().split()))
tuesday = list(map(int, input().split()))

tuesday.sort()

for i in range(n):
    foundIndex = bisect.bisect_left(tuesday, monday[i])

    if foundIndex < len(tuesday) and tuesday[foundIndex] == monday[i]:
        print(f"{monday[i]} ", end="")

print()