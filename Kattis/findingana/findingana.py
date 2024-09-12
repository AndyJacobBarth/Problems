compString = input()

compString_length = len(compString)

for i in range(compString_length):
    if compString[i] == 'a':
        print(compString[i:])
        break