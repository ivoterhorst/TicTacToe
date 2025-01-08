#include "game.hpp"

#include <iostream>

Game::Game() : board() {}

void Game::play()
{
    board.display();
    char player = 'X';
    while (!board.isFull())
    {
        int row, col;
        do
        {
            std::cout << "Player " << player << ": Enter row and column: ";
            std::cin >> row >> col;

        } while (!board.makeMove(row, col, player));
        board.display();
        if (board.checkWin(player))
        {
            std::cout << player << " wins!" << std::endl;
            return;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    std::cout << "It's a tie!" << std::endl;
}