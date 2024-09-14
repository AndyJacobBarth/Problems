#include <iostream>
#include <string>

int main() {
    std::string userInput;
    std::cin >> userInput;

    if (userInput.find("COV") == std::string::npos) {
        std::cout << "Ekki Veikur!\n";
    }
    else {
        std::cout << "Veikur!\n";
    }
    return 0;
}
