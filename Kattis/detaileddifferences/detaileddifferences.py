n = int(input())

while n > 0:
    s1 = input()
    s2 = input()
    s1_length = len(s1)

    print(s1)
    print(s2)

    for i in range(s1_length):
        if s1[i] == s2[i]:
            print(".", end="")
        else:
            print("*", end="")
    print()
    n -= 1