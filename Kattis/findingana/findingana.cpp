#include <iostream>
#include <string>

int main() {
    std::string compString;
    std::cin >> compString;

    int compString_length = compString.length();
    for (int i = 0; i < compString_length; i++) {
        if (compString[i] == 'a') {
            std::cout << compString.substr(i) << "\n";
            return 0;
        }
    }
    return 0;
}
