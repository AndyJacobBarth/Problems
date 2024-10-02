#include <iostream>
#include <iomanip>

int main() {
    float C;
    int L;
    std::cin >> C >> L;
    float totalArea = 0;

    while (L > 0) {
        float l, w;
        std::cin >> l >> w;

        totalArea += l * w;
        L--;
    }

    std::cout << std::fixed << std::setprecision(6) << C * totalArea << "\n";
    return 0;
}
