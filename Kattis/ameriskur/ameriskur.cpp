#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(6) << n * 0.09144 << "\n";
    return 0;
}
