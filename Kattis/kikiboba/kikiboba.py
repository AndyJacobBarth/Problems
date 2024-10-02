compString = input()
b = 0
k = 0

for c in compString:
    if c == 'b':
        b += 1
    if c == 'k':
        k += 1

if b == 0 and k == 0:
    print("none")
elif b < k:
    print("kiki")
elif k < b:
    print("boba")
else:
    print("boki")