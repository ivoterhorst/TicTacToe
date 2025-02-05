#pragma once

#include "types.hpp"

using tictactoe::Move;
using tictactoe::PlayerId;

class Player
{
public:
    Player(PlayerId id) { this->id = id; };
    virtual ~Player() {};
    virtual Move getMove() const = 0;
    PlayerId getId() const { return id; }

protected:
    PlayerId id;
};
