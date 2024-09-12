n = input()
count = 0

for x in n:
    if x >= 'a' and x <= 'z':
        count += 1
    if x >= 'A' and x <= 'Z':
        count += 1

print(count)