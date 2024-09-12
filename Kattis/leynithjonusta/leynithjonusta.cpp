#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); 

    std::string strings;
    std::getline(std::cin, strings);

    for (char s : strings) {
        if (s != ' ') {
            std::cout << s;
        }
    }
    std::cout << '\n';
    return 0;
}
