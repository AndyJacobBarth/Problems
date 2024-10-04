#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string startWord;
    std::string endWord;
    std::cin >> startWord >> endWord;
    int total = 1, wordLength = startWord.length();

    for (int i = 0; i < wordLength; i++) {
        if (startWord[i] != endWord[i])
            total++;
    }

    std::cout << total << "\n";
    return 0;
}
