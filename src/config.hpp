#pragma once

#include <filesystem>

#include "config.hh"


class Config {
public:
    Config();
    ~Config();

    bool isAllowed(std::filesystem::path p);
    void allow(std::filesystem::path p);

    std::filesystem::path _configPath;
};