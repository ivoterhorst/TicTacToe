#pragma once

#include "types.hpp"
#include "player.hpp"

using tictactoe::Move;

class HumanPlayer : public Player
{
public:
    using Player::Player; // inherit constructor
    Move getMove() const override;
};
