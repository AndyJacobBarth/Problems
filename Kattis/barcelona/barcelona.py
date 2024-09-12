n, k = input().split()

index = 1

for a in input().strip().split():
    if a == k:
        if index == 1:
            print("fyrst")
            break
        if index == 2:
            print("naestfyrst")
            break
        print(f"{index} fyrst")
        break
    index += 1