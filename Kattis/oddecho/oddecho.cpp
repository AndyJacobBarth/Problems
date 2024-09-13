#include <iostream>
#include <string>

int main() {
    int n;
    std::string oddInput, evenInput;
    std::cin >> n;

    while (n > 1) {
        std::cin >> oddInput >> evenInput;
        std::cout << oddInput << "\n";
        n -= 2;
    }
    if (n == 1) {
        std::cin >> oddInput;
        std::cout << oddInput << "\n";
    }
    return 0;
}
