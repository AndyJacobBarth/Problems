#include <iostream>
#include <string>

int main() {
    std::string s;
    int digit;
    std::cin >> s >> digit;
    while (digit > 0) {
        std::cout << s;
        digit--;
    }
    std::cout << std::endl;
    return 0;
}
