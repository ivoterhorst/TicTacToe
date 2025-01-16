#pragma once

#include "lib/types.hpp"

class StartingPlayerChooser
{
public:
    virtual ~StartingPlayerChooser() {}
    virtual PlayerId chooseStartingPlayer() = 0;
};