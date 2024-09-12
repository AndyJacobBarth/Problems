#include <iostream>

int main() {
    int xh, yh, xp, yp;
    std::cin >> xh >> yh >> xp >> yp;

    if (xh == xp || yh == yp)
        std::cout << 1 << "\n";
    else
        std::cout << 2 << "\n";
    return 0;
}
