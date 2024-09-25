P = int(input())

while P > 0:
    K, N = input().split()
    K = int(K)
    N = int(N)

    print(f"{K} {N * (N+3) // 2}")

    P -= 1