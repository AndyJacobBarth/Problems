#include <iostream>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    int monday[n];
    int tuesday[m];

    for (int i = 0; i < n; i++) {
        int student;
        std::cin >> student;
        monday[i] = student;
    }

    for (int i = 0; i < m; i++) {
        int student;
        std::cin >> student;
        tuesday[i] = student;
    }

    std::sort(tuesday, tuesday + m);

    for (int i = 0; i < n; i++) {
        bool found = std::binary_search(tuesday, tuesday + n, monday[i]);
        if (found)
            std::cout << monday[i] << " ";
    }

    std::cout << "\n";

    return 0;
}
