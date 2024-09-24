comp_string = input()
comp_string_length = len(comp_string)
hissed = False

for i in range(comp_string_length):
    if comp_string[i] == 's':
        if i < comp_string_length - 1 and comp_string[i + 1] == 's':
            print("hiss")
            hissed = True
            break
        else:
            i += 1

if not hissed:
    print("no hiss")