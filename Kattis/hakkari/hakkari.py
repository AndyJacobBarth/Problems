n, m = map(int, input().split())
num_bombs = 0
bomb_locations = []

for i in range(n):
    row = input()

    for j in range(m):
        if row[j] == '*':
            num_bombs += 1
            bomb_locations.append((i + 1, j + 1))

print(num_bombs)

for location in bomb_locations:
    print(f"{location[0]} {location[1]}")