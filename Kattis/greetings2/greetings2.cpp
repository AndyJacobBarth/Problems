#include <iostream>
#include <string>

int main() {
    std::string hey;
    std::cin >> hey;
    int heyLength = hey.length();
    
    std::cout << "h";

    for (int i = 0; i < heyLength - 2; i++) {
        std::cout << "ee";
    }

    std::cout << "y\n";
    return 0;
}
