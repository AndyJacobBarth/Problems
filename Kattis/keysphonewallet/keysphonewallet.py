N = int(input())
inventory = ["keys", "phone", "wallet"]

while N > 0:
    item = input()

    for essentials in inventory:
        if item == essentials:
            inventory.remove(essentials)
    N -= 1

if not inventory:
    print("ready")
else:
    for essentials in inventory:
        print(essentials)