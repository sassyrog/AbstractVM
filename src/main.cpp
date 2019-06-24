#include <iostream>
#include <regex>
#include "../inc/AVM.hpp"

int main(int ac, char **av) {
    std::string input;
    if (ac == 1) {
        AVM avm;
    } else {
        for (int i = 1; i < ac; i++) {
            AVM avm(av[i]);
        }
    }

    return 0;
}
