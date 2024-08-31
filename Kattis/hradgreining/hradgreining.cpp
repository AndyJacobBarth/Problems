#include <iostream>
#include <string>

int main() {
    std::string userInput;
    std::string cov = "COV";

    std::cin >> userInput;

    if (userInput.find(cov) == std::string::npos) {
        std::cout << "Ekki Veikur!\n";
    }
    else {
        std::cout << "Veikur!\n";
    }
    return 0;
}
