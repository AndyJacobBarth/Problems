s = int(input())

hours = s // 3600
s -= 3600 * hours
minutes = s // 60
s -= 60 * minutes

print(f"{hours} : {minutes} : {s}")