#include <iostream>

#include "bde.hpp"


int main(int argc, char const *argv[]) {
    Bde shellEnv;
    if (argc == 2) {
        if (argv[1] == std::string("allow")) {
            shellEnv.allow();
            std::cout << ".bderc allowed!" << std::endl;
            return 0;
        } else if (argv[1] == std::string("exec")) {
            shellEnv.checkForBderc();
            return 0;
        } else {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
    }
    std::cout << "Invalid argument" << std::endl;
    return 1;
}