#include <iostream>
#include <string>

int main() {
    std::string names;
    std::cin >> names;
    int names_length = names.length();
    std::cout << names[0];
    for (int i = 0; i < names_length; i++) {
        if (names[i] == '-') {
            std::cout << names[i+1];
        }
    }
    std::cout << "\n";
    return 0;
}
