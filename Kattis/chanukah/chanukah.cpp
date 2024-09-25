#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int P;
    std::cin >> P;

    while (P > 0) {
        int K, N;
        std::cin >> K >> N;

        std::cout << K << " " << N * (N + 3) / 2 << "\n";

        P--;
    }
    return 0;
}
