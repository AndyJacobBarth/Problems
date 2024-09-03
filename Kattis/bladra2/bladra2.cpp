#include <iostream>

int main() {
    int v, a, t;
    std::cin >> v >> a >> t;
    std::cout << t*(v + 0.5 * a * t) << std::endl;
    return 0;
}
