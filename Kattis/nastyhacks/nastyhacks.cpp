#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n > 0) {
        int r, e, c;
        std::cin >> r >> e >> c;

        if (e - c > r) {
            std::cout << "advertise\n";
        }
        else if (e - c < r) {
            std::cout << "do not advertise\n";
        }
        else {
            std::cout << "does not matter\n";
        }
        n--;
    }
    return 0;
}
