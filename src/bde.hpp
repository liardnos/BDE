#pragma once

#include <memory>

#include "bde.hh"
#include "config.hpp"

class Bde {
public:
    Bde();
    ~Bde();

    bool checkForBderc();
    void exec();
    void allow();


    Config _config;
};
