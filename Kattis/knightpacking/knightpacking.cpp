#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if (N & 1 == 1)
        std::cout << "first\n";
    else
        std::cout << "second\n";
    return 0;
}
