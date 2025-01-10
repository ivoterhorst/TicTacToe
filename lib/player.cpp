#include "player.hpp"
#include "lib/types.hpp"

#include <iostream>

// Player::Player(PlayerId id, Board *board) : id(id), board(board) {}
Player::Player(PlayerId id) : id(id) {}

Move Player::getMove() const
{
    Move move;
    std::cout << "Player " << (id == PlayerId::X ? 'X' : 'O') << ", enter your move (row col): ";
    std::cin >> move.row >> move.col;
    return move;
}
