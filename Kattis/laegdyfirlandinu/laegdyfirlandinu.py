import sys

n, m = map(int, input().split())
forecasts = []

for i in range(n):
    forecasts.append(list(map(int, input().split())))

for i in range(1, n - 1):
    for j in range(1, m - 1):
        currentForecast = forecasts[i][j]

        if (forecasts[i-1][j] > currentForecast and
            forecasts[i+1][j] > currentForecast and
            forecasts[i][j-1] > currentForecast and
            forecasts[i][j+1] > currentForecast):
            print("Jebb")
            sys.exit(0)

print("Neibb")