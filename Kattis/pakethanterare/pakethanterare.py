t, b = map(int, input().split())
stores = []
currentVersion = {}

stores = list(map(int, input().split()))

for i in range(t):
    packageType, v = input().split()
    v = int(v)

    currentVersion[packageType] = v

for store in stores:
        versionDifference = 0

        for j in range(store):
            packageType, v = input().split()
            v = int(v)

            versionDifference += currentVersion[packageType] - v

        print(versionDifference)
