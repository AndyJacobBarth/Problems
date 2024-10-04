#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t, b;
    std::cin >> t >> b;
    int stores[b];
    std::unordered_map<std::string, int> currentVersion;

    for (int i = 0; i < b; i++) {
        std::cin >> stores[i];
    }

    for (int i = 0; i < t; i++) {
        std::string packageType;
        int v;
        std::cin >> packageType >> v;
        currentVersion[packageType] = v;
    }

    for (int i = 0; i < b; i++) {
        int versionDifference = 0;
        for (int j = 0; j < stores[i]; j++) {
            std::string packageType;
            int v;
            std::cin >> packageType >> v;

            versionDifference += currentVersion[packageType] - v;
        }
        
        std::cout << versionDifference << "\n";
    }
    return 0;
}
