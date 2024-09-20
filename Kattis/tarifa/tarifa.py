X = int(input())
N = int(input())

answer = X * (N + 1)

while N > 0:
    P = int(input())
    answer -= P

    N -= 1
    
print(answer)