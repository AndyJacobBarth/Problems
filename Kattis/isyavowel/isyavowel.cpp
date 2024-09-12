#include <iostream>
#include <string>

int main() {
    std::string compString;
    std::cin >> compString;
    std::string vowels = "aeiou";
    int count1 = 0, count2 = 0;
    int compString_length = compString.length();

    for (int i = 0; i < compString_length; i++) {
        for (int j = 0; j < 5; j++) {
            if (compString[i] == vowels[j]) {
                count1++;
                count2++;
            }
        }
        if (compString[i] == 'y') {
            count2++;
        }
    }
    std::cout << count1 << " " << count2 << "\n";
    return 0;
}
