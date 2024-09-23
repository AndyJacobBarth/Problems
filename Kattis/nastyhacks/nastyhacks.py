n = int(input())

while n > 0:
    r, e, c = input().split()
    r = int(r)
    e = int(e)
    c = int(c)

    if e - c > r:
        print("advertise")
    elif e - c < r:
        print("do not advertise")
    else:
        print("does not matter")
    
    n -= 1