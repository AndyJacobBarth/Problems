M = int(input())
sum = 0

T = list(map(int, input().split()))

for Ti in T:
    sum += Ti

print(sum // M)