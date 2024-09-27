s = input()
vowels = "aeiouAEIOU"
total = 0

for c in s:
    for vowel in vowels:
        if c == vowel:
            total += 1

print(total)