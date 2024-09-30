#include <iostream>

int main() {
    int B, L;
    std::cin >> B >> L;
    if (B < L)
        std::cout << 2*B << "\n";
    else
        std::cout << 2*L << "\n";
    return 0;
}
