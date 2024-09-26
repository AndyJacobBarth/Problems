#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;
    if (n.substr(0, 3) == "555")
        std::cout << 1 << "\n";
    else
        std::cout << 0 << "\n";
    return 0;
}
