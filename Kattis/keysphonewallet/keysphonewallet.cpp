#include <iostream>
#include <vector>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> inventory = {"keys", "phone", "wallet"};

    while (N > 0) {
        std::string item;
        std::cin >> item;

        for (int i = 0; i < inventory.size(); i++)  {
            if (item == inventory[i])
                inventory.erase(inventory.begin() + i);
        }
        N--;
    }

    if (inventory.empty()) {
        std::cout << "ready\n";
    }
    else {
        for (std::string essentials : inventory) {
            std::cout << essentials << "\n";
        }
    }
    return 0;
}
