#include <iostream>

int main() {
    int T;
    std::cin >> T;
    
    while (T > 0) {
        int N;
        std::cin >> N;

        if (N == 1 || N == 2 || N == 4)
            std::cout << N << "\n";
        else if (N == 3)
            std::cout << 6 << "\n";
        else
            std::cout << 0 << "\n";

        T--;
    }
    return 0;
}
