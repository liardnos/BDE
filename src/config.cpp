#include <fstream>
#include <iostream>
#include <filesystem>

#include "lib/json.hpp"
#include "config.hpp"


Config::Config() {
    std::filesystem::path homeDir = std::filesystem::path(std::getenv("HOME"));
    _configPath =  homeDir/".config/bde/config.json";
    std::cout << _configPath << std::endl;
    std::ifstream i(_configPath);
    try {
        if (i.is_open()) {
            nlohmann::json j;
            i >> j;
        } else {
            std::cout << "Error opening config file" << std::endl;
            std::cout << "Creating new config file (" << _configPath << ")"  << std::endl;
            std::filesystem::create_directory(homeDir/".config/bde/");
            std::ofstream o(_configPath);
            o << "{}";
        }
    } catch (nlohmann::json::parse_error& e) {
        std::cout << "Error parsing config file" << std::endl;
    }
}

Config::~Config() {
}

bool Config::isAllowed(std::filesystem::path p) {
    p = std::filesystem::absolute(p);
    size_t t = std::filesystem::last_write_time(p).time_since_epoch().count();

    std::ifstream i(_configPath);
    nlohmann::json j;
    i >> j;
    return j[p]["time"] == t;
}

void Config::allow(std::filesystem::path p) {
    p = std::filesystem::absolute(p);
    size_t t = std::filesystem::last_write_time(p).time_since_epoch().count();

    std::ifstream i(_configPath);
    nlohmann::json j;
    i >> j;
    j[p]["time"] = t;
    std::ofstream o(_configPath);
    o << j;
    std::cout << "Allowed" << std::endl;
}
