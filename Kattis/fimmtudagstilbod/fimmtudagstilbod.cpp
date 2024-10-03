#include <iostream>

int main() {
    int y;
    std::cin >> y;

    if (y <= 2020)
        std::cout << 1000 << "\n";
    else
        std::cout << 1000 + 100*(y - 2020) << "\n";
    return 0;
}
