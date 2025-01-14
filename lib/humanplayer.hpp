#pragma once

#include "types.hpp"
#include "player.hpp"

class HumanPlayer : public Player
{
public:
    using Player::Player; // inherit constructor
    Move getMove() const override;
};
