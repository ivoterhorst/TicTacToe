#include "game.hpp"
#include "types.hpp"
#include "startingplayerchooser.hpp"

#include <iostream>
#include <memory>
#include <ctime>

Game::Game(std::shared_ptr<Board> board,
           std::shared_ptr<Player> player1,
           std::shared_ptr<Player> player2,
           std::shared_ptr<StartingPlayerChooser> startingPlayerChooser) : board(board),
                                                                           player1(player1),
                                                                           player2(player2),
                                                                           startingPlayerChooser(startingPlayerChooser) {}

void Game::play()
{
    board->display();

    // pick random player to start
    std::shared_ptr<Player> currentPlayer = (startingPlayerChooser->chooseStartingPlayer() == PlayerId::X) ? player1 : player2;

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