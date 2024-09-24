#include <iostream>
#include <string>

int main() {
    std::string comp_string;
    std::cin >> comp_string;

    int comp_string_length = comp_string.length();

    for (int i = 0; i < comp_string_length; i++) {
        if (comp_string[i] == 's') {
            if (comp_string[i + 1] == 's') {
                std::cout << "hiss\n";
                return 0;
            }
            else {
                i++;
            }
        }
    }
    
    std::cout << "no hiss\n";
    return 0;
}
