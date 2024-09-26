T = int(input())

while T > 0:
    N = int(input())

    if N == 1 or N == 2 or N == 4:
        print(N)
    elif N == 3:
        print(6)
    else:
        print(0)
        
    T -= 1