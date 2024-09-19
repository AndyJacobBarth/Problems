N = int(input())
answer = 0

while N > 0:
    answer <<= 1
    answer += N & 1
    N >>= 1

print(answer)