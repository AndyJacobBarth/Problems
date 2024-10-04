n = int(input())
words = input().split()

for word in words:
    if word[0].isupper():
        print(word[0], end="")

print()