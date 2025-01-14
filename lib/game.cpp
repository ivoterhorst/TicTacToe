#include "game.hpp"
#include "types.hpp"

#include <iostream>
#include <memory>

Game::Game(std::shared_ptr<Board> board,
           std::shared_ptr<Player> player1,
           std::shared_ptr<Player> player2) : board(board),
                                              player1(player1),
                                              player2(player2) {}

void Game::play()
{
    board->display();

    // pick random player to start
    std::shared_ptr<Player> currentPlayer;
    std::srand(std::time(nullptr));                            // seed random number generator with current time
    int zeroOrOne = (1 + std::rand()) / ((RAND_MAX + 1u) / 2); // Note: 1 + rand() % sides is biased
    if (zeroOrOne == 0)
    {
        currentPlayer = player1;
    }
    else
    {
        currentPlayer = player2;
    }

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
            std::cout << currentPlayer->getId() << " wins!" << std::endl;
            return;
        }
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
    std::cout << "It's a tie!" << std::endl;
}