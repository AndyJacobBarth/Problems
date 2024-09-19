#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int total = 0;

    while (n > 0) {
        int t;
        std::cin >> t;
        if (t < 0)
            total++;
        n--;
    }
    std::cout << total << "\n";
    return 0;
}
