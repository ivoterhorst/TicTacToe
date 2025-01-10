#include "game.hpp"
#include "types.hpp"
#include "utils.hpp"

#include <iostream>

Game::Game(std::shared_ptr<Board> board,
           std::shared_ptr<Player> player1,
           std::shared_ptr<Player> player2) : board(board),
                                              player1(player1),
                                              player2(player2) {}

void Game::play()
{
    board->display();
    std::shared_ptr<Player> currentPlayer = player1; // start with player 1
    while (!board->isFull())
    {
        Move move;
        do
        {
            move = currentPlayer->getMove();
        } while (!board->makeMove(move, currentPlayer->getId()));
        board->display();
        if (board->checkWin(currentPlayer->getId()))
        {
            std::cout << playerIdToString(currentPlayer->getId()) << " wins!" << std::endl;
            return;
        }
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
    std::cout << "It's a tie!" << std::endl;
}