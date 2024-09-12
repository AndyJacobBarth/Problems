#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k, a1;
    std::cin >> n >> k >> a1;

    if (a1 == k) {
        std::cout << "fyrst\n";
    }
    else {
        int a2;
        std::cin >> a2;

        if (a2 == k) {
            std::cout << "naestfyrst\n";
        }
        else {
            for (int i = 3; i <= n; i++) {
                int a;
                std::cin >> a;
                if (a == k) {
                    std::cout << i << " fyrst\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
