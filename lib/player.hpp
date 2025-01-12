#pragma once

#include "types.hpp"

class Player
{
public:
    Player(PlayerId id) { this->id = id; };
    virtual Move getMove() const = 0;
    PlayerId getId() const { return id; }

protected:
    PlayerId id;
};
