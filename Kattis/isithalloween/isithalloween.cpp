#include <iostream>
#include <string>

int main() {
    std::string date;
    std::getline(std::cin, date);

    if (date == "OCT 31" || date == "DEC 25") {
        std::cout << "yup\n";
    }
    else {
        std::cout << "nope\n";
    }
    return 0;
}
