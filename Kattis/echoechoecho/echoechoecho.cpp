#include <iostream>

int main() {
    std::string word;
    std::cin >> word;
    for (int i = 0; i < 3; i++) {
        std::cout << word << " ";
    }
    std::cout << "\n";
    return 0;
}
