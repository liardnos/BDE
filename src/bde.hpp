#pragma once

#include <memory>

#include "bde.hh"
#include "config.hpp"

class Bde {
public:
    Bde();
    ~Bde();

    void checkForBderc();
    void allow();

    Config _config;
};
