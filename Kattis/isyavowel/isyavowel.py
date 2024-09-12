compString = input()
vowels = "aeiou"

count1 = 0
count2 = 0

for char in compString:
    for vowel in vowels:
        if char == vowel:
            count1 += 1
            count2 += 1
    if char == 'y':
        count2 += 1

print(f"{count1} {count2}")