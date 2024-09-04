#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::string meat;
        std::cin >> meat;
        std::cout << meat << std::endl;
    }
    else {
        std::cout << "blandad best\n";
    }
    return 0;
}
