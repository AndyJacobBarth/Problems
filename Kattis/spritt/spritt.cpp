#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    while (n > 0) {
        int ai;
        std::cin >> ai;
        x -= ai;
        if (x < 0) {
            std::cout << "Neibb\n";
            return 0;
        }
        n--;
    }
    std::cout << "Jebb\n";
    return 0;
}
