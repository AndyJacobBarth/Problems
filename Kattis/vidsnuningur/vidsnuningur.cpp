#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string userInput;
    std::cin >> userInput;

    // Directly modifies userInput
    std::reverse(userInput.begin(), userInput.end());

    std::cout << userInput << std::endl;

    return 0;
}