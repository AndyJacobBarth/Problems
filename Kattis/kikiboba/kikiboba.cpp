#include <iostream>
#include <string>

int main() {
    std::string compString;
    std::cin >> compString;
    int b = 0, k = 0;

    for (char c : compString) {
        if (c == 'b')
            b++;
        if (c == 'k')
            k++;
    }

    if (b == 0 && k == 0)
        std::cout << "none\n";
    else if (b < k)
        std::cout << "kiki\n";
    else if (k < b)
        std::cout << "boba\n";
    else
        std::cout << "boki\n";
    return 0;
}
