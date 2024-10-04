#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> memes;
    memes.reserve(n);

    int bestScore = 0;

    while (n > 0) {
        std::string meme;
        int contro, cool, fresh;
        std::cin >> meme >> contro >> cool;
        fresh = contro * cool;
        if (bestScore <= fresh) {
            bestScore = fresh;
            memes.push_back({meme, fresh});
        }
        n--;
    }

    std::sort(memes.begin(), memes.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    std::cout << memes[0].first << "\n";
    return 0;
}
