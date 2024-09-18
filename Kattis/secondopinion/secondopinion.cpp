#include <iostream>

int main() {
    int s;
    std::cin >> s;

    int hours = s / 3600;
    s -= 3600 * hours;
    int minutes = s / 60;
    s -= 60 * minutes;

    std::cout << hours << " : " << minutes << " : " << s << "\n";
    return 0;
}
