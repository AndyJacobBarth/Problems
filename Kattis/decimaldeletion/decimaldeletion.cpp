#include <iostream>

int main() {
    float N;
    std::cin >> N;
    if (N - (int) N > 0.5) {
        std::cout << (int) N + 1 << "\n";
    }
    else {
        std::cout << (int) N << "\n";
    }
    return 0;
}
