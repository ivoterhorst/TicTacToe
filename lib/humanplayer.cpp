#include "humanplayer.hpp"
#include "lib/types.hpp"

#include <iostream>

Move HumanPlayer::getMove() const
{
    Move move;
    std::cout << "Player " << id << ", enter your move (row col): ";
    std::cin >> move.row >> move.col;
    return move;
}
