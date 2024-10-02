C = float(input())
L = int(input())
totalArea = 0

while L > 0:
    l, w = map(float, input().split())

    totalArea += l * w
    L -= 1

print(C * totalArea)