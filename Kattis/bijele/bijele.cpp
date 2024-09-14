#include <iostream>

int main() {
    int expected[] = {1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; i++) {
        int piece;
        std::cin >> piece;
        expected[i] -= piece;
    }

    for (int i : expected) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
