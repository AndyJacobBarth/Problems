#include <iostream>

int main() {
    int N;
    std::cin >> N;
    float sum = 0;

    while (N > 0) {
        float q, y;
        std::cin >> q >> y;

        sum += q * y;

        N--;
    }
    std::cout << sum << "\n";
    return 0;
}
