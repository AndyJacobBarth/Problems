#include <iostream>

int main() {
    int M;
    std::cin >> M;
    int sum = 0;

    for (int i = 0; i < M; i++) {
        int T;
        std::cin >> T;

        sum += T;
    }

    std::cout << sum / M << "\n";
    return 0;
}
