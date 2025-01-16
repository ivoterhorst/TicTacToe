#pragma once

#include "board.hpp"
#include "player.hpp"
#include "startingplayerchooser.hpp"

#include <memory>

class Game
{
public:
    Game(std::shared_ptr<Board> board,
         std::shared_ptr<Player> player1,
         std::shared_ptr<Player> player2,
         std::shared_ptr<StartingPlayerChooser> startingPlayerChooser);
    void play();

private:
    std::shared_ptr<Board> board;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<StartingPlayerChooser> startingPlayerChooser;
};
