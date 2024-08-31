#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) {
        std::cout << "MAGA!\n";
    }
    else if (b > a) {
        std::cout << "FAKE NEWS!\n";
    }
    else {
        std::cout << "WORLD WAR 3!\n";
    }
    return 0;
}
