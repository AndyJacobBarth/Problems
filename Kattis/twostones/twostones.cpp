#include <iostream>

int main() {
    int N;
    std::cin >> N;
    if (N & 1 == 1)
        std::cout << "Alice\n";
    else
        std::cout << "Bob\n";
    return 0;
}
