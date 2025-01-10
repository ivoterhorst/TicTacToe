#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "player.hpp"

class Game
{
public:
    Game(std::shared_ptr<Board> board, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
    void play();

private:
    std::shared_ptr<Board> board;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
};

#endif // GAME_HPP