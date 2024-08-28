#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;
    if (n.back() == '0')
        std::cout << "Jebb\n";
    else
        std::cout << "Neibb\n";
    return 0;
}
