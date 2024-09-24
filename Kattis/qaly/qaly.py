N = int(input())
sum = 0

while N > 0:
    q, y = input().split()
    q = float(q)
    y= float(y)

    sum += q * y

    N -= 1
print(sum)