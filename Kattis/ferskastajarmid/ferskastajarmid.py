n = int(input())
memes = []
bestScore = 0

while n > 0:
    meme, contro, cool = input().split()
    contro = int(contro)
    cool = int(cool)
    fresh = contro * cool

    if bestScore <= fresh:
        bestScore = fresh
        memes.append((meme, fresh))

    n -= 1

memes.sort(key=lambda x: (-x[1], x[0]))

print(memes[0][0])