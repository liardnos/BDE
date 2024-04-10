
#include <fstream>
#include <filesystem>
#include <iostream>

#include "lib/json.hpp"
#include "bde.hpp"

Bde::Bde() {
}

Bde::~Bde() {
}

void Bde::checkForBderc() {
    std::ifstream i(".bderc");
    if (!i.is_open()) {
        std::cout << "No .bderc file" << std::endl;
        return;
    }
    std::cout << ".bderc file found!" << std::endl;
    if (_config.isAllowed(std::filesystem::current_path()/".bderc")) {
        std::cout << "Allowed" << std::endl;
    } else {
        std::cout << "Not allowed" << std::endl;
    }
}

void Bde::allow() {
    _config.allow(std::filesystem::current_path()/".bderc");
}