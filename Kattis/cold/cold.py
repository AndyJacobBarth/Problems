input()
total = 0
for temps in input().split():
    if int(temps) < 0:
        total += 1

print(total)