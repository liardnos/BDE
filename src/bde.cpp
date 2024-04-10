
#include <fstream>
#include <filesystem>
#include <iostream>

#include "lib/json.hpp"
#include "bde.hpp"

Bde::Bde() {
}

Bde::~Bde() {
}

bool Bde::checkForBderc() {
    std::ifstream i(".bderc");
    if (!i.is_open()) {
        std::cout << "No .bderc file" << std::endl;
        return false;
    }
    std::cout << ".bderc file found!" << std::endl;
    if (_config.isAllowed(std::filesystem::current_path()/".bderc")) {
        std::cout << "Allowed" << std::endl;
        return true;
    } else {
        std::cout << "Not allowed" << std::endl;
    }
    return false;
}

void Bde::exec() {
    if (!checkForBderc())
        return;
    std::cout << "starting new bash" << std::endl;
    exit(system("bash"));
}

void Bde::allow() {
    _config.allow(std::filesystem::current_path()/".bderc");
}