#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    while (n > 0) {
        std::string word;
        std::cin >> word;

        if (word[0] >= 'A' && word[0] <= 'Z')
            std::cout << word[0];

        n--;
    }
    return 0;
}
