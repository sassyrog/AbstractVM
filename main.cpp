#include <iostream>
#include <regex>
// #include "AVM.hpp"

int main(int ac, char *av[]) {
    std::string input;
    if (ac == 1) {
        while (1) {
            std::getline(std::cin, input);
            std::cout << input << std::endl;
        }
    } else {
        std::cout << av[1] << std::endl;
    }

    return 0;
}
