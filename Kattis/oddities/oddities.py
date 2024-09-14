n = int(input())

while (n > 0):
    x = int(input())

    if x & 1 == 1:
        print(f"{x} is odd")
    else:
        print(f"{x} is even")
        
    n -= 1