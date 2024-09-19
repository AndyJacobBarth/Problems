#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int answer = 0;

    while (N > 0) {
        answer <<= 1;
        answer += N & 1;
        N >>= 1;
    }
    std::cout << answer << "\n";
    return 0;
}
