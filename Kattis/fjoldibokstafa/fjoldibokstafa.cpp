#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;
    int count = 0;

    for (char x : n) {
        if (x >= 'A' && x <= 'Z')
            count++;
        else if (x >= 'a' && x <= 'z')
            count++;
    }
    std::cout << count << "\n";
}
