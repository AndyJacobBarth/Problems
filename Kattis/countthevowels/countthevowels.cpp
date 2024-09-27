#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string vowels = "aeiouAEIOU";
    int total = 0;

    for (char c : s) {
        for (char vowel : vowels) {
            if (c == vowel)
                total++;
        }
    }

    std::cout << total << "\n";
    return 0;
}
