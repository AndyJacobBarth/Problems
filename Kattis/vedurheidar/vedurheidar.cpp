#include <iostream>
#include <string>

int main() {
    int v, n;
    std::cin >> v >> n;

    while (n > 0) {
        std::string s;
        int k;

        std::cin >> s >> k;

        if (v > k) {
            std::cout << s << " lokud\n";
        }
        else {
            std::cout << s << " opin\n";
        }
        n--;
    }
    return 0;
}
