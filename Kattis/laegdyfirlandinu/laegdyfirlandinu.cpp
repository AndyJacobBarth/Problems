#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int forecasts[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> forecasts[i][j];
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int currentForecast = forecasts[i][j];

            if (forecasts[i-1][j] > currentForecast &&
                forecasts[i+1][j] > currentForecast &&
                forecasts[i][j-1] > currentForecast &&
                forecasts[i][j+1] > currentForecast
            ) {
                std::cout << "Jebb\n";
                return 0;
            }
        }
    }

    std::cout << "Neibb\n";
    return 0;
}
