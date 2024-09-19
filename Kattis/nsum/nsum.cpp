#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int sum = 0;

    while (N > 0) {
        int num;
        std::cin >> num;
        sum += num;
        N--;
    }
    std::cout << sum << "\n";
    return 0;
}
