#include <iostream>

int main() {
    int N, l;
    std::cin >> N;
    int sum = 1 - N;

    while (N > 0) {
        std::cin >> l;
        sum += l;
        N--;
    }
    std::cout << sum << "\n";
    return 0;
}
