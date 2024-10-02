#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    int numBombs = 0;
    std::vector<std::pair<int, int>> bombLocations;
    bombLocations.reserve(n * m);

    for (int i = 0; i < n; i++) {
        std::string row;
        std::cin >> row;

        for (int j = 0; j < m; j++) {
            if (row[j] == '*') {
                numBombs++;
                bombLocations.push_back({i + 1, j + 1});
            }
        }
    }

    std::cout << numBombs << "\n";

    for (std::pair location : bombLocations) {
        std::cout << location.first << " " << location.second << "\n";
    }
    return 0;
}
