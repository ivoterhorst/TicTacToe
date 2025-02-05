#pragma once

#include "lib/types.hpp"

using tictactoe::PlayerId;

class StartingPlayerChooser
{
public:
    virtual ~StartingPlayerChooser() {}
    virtual PlayerId chooseStartingPlayer() = 0;
};