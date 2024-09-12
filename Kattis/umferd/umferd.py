m = input()
n = input()

m = int(m)
n = float(n)

totalSpace = m * n
availableSpace = 0

while n > 0:
    traffic = input()
    for spot in traffic:
        if spot == '.':
            availableSpace += 1
    n -= 1

print(availableSpace / totalSpace)