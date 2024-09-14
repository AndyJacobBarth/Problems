#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n > 0) {
        int x;
        std::cin >> x;

        if (x & 1 == 1) {
            std::cout << x << " is odd\n";
        }
        else {
            std::cout << x << " is even\n";
        }
        n--;
    }
    return 0;
}
