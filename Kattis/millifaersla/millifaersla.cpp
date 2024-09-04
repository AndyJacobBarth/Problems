#include <iostream>

int main() {
    int a,b,c, lowest;
    std::cin >> a >> b >> c;
    if (a < b)
        if (a < c)
            std::cout << "Monnei\n";
        else
            std::cout << "Dolladollabilljoll\n";
    else if (b < c)
        std::cout << "Fjee\n";
    else
        std::cout << "Dolladollabilljoll\n";
}
