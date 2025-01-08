#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class Game
{
public:
    Game();
    void play();

private:
    Board board;
};

#endif // GAME_HPP