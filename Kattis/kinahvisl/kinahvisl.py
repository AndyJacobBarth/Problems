start_word = input()
end_word = input()
total = 1
start_word_length = len(start_word)

for i in range(start_word_length):
    if start_word[i] != end_word[i]:
        total += 1

print(total)