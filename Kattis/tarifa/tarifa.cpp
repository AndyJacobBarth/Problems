#include <iostream>

int main() {
    int X, N;
    std::cin >> X >> N;
    
    int answer = X * (N + 1);

    while (N > 0) {
        int P;
        std::cin >> P;
        answer -= P;

        N--;
    }

    std::cout << answer << "\n";
    return 0;
}
