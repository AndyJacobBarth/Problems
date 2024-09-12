#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int m, n;
    std::cin >> m >> n;
    float totalSpace = m * n;
    int availableSpace = 0;

    while (n > 0) {
        std::string traffic;
        std::cin >> traffic;
        for (char spot : traffic) {
            if (spot == '.') {
                availableSpace++;
            }
        }
        n--;
    }
    std::cout << availableSpace / totalSpace << "\n";
    return 0;
}
