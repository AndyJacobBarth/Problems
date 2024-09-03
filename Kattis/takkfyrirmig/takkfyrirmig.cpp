#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    while (n > 0) {
        std::string name;
        std::cin >> name;
        std::cout << "Takk " + name << std::endl;
        n--;
    }
    return 0;
}
