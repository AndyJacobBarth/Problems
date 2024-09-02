#include <iostream>
#include <string>

int main() {
    int n, fun_metric, best_metric;
    std::string name, best_name;

    std::cin >> n >> name >> fun_metric;
    best_name = name;
    best_metric = fun_metric;

    while (n > 0) {
        std::cin >> name >> fun_metric;
        if (fun_metric > best_metric) {
           best_metric = fun_metric;
           best_name = name;
        }
        n--;
    }
    std::cout << best_name << std::endl;
    return 0;
}
