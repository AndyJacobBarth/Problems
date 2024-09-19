#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n > 0) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int s1_length = s1.length();

        std::cout << s1 << "\n" << s2 << "\n";

        for (int i = 0; i < s1_length; i++) {
            if (s1[i] == s2[i]) {
                std::cout << ".";
            }
            else {
                std::cout << "*";
            }
        }
        std::cout << "\n";
        n--;
    }
    return 0;
}
