#include <iostream>

int main() {
    int m;
    std::cin >> m;
    
    if (m == 2)
        std::cout << 28 << std::endl;
    else if(m == 4 || m == 6 || m == 9 || m == 11)
        std::cout << 30 << std::endl;
    else
        std::cout << 31;
    return 0;
}
