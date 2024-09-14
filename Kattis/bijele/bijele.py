expected = [1, 1, 2, 2, 2, 8]
pieces = input().split()
for i in range(6):
    expected[i] -= int(pieces[i])

for i in expected:
    print(f"{i} ", end="")
print()