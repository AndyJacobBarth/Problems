names = input()
names_length = len(names)
print(names[0], end="")

for i in range(names_length):
    if names[i] == '-':
        print(names[i + 1], end="")
print()