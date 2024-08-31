#include <iostream>
#include "kmp_algorithm.h"

int main() {
    std::string userText;
    std::string userPattern;
    int prefix_table[userPattern.length()];

    std::cout << "Enter text: ";
    std::cin >> userText;
    std::cout << "Enter pattern to search: ";
    std::cin >> userPattern;

    //Show the Prefix table
    lps_algorithm(userPattern, prefix_table);
    std::cout << "Prefix Table:\n[ ";
    for (int i = 0; i < userPattern.length(); i++) {
        std::cout << prefix_table[i] << " ";
    }
    std::cout << "]\n";

    // Show first index of occurrence, or -1 if no result
    int index_of_occurrence = kmp_search(userText, userPattern);
    std::cout << "Matching index: " << index_of_occurrence << std::endl;
    std::cout << userText << std::endl;

    // Print if not found
    if (index_of_occurrence == -1)
        std::cout << "Not found\n";

    // Show where first instance is found within text
    else {
        for (int i = 0; i < index_of_occurrence; i++) {
            std::cout << " ";
        }
        for (int i = index_of_occurrence; i < index_of_occurrence + userPattern.length(); i++) {
            std::cout << "^";
        }
        std::cout << std::endl;
    }
    return 0;
}

