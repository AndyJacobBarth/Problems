#include <iostream>
#include <string>

int main() {
    std::string name;
    int x;

    std::cin >> name >> x;

    while (x > 0) {
        std::cout << "Hipp hipp hurra, " + name + "!\n";
        x--;
    }
    return 0;
}
