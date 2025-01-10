#ifndef PLAYER_HPP
#define PLAYER_HPP

// #include "board.hpp"
#include "types.hpp"

class Player
{
public:
    // Player(PlayerId id, Board *board);
    Player(PlayerId id);
    Move getMove() const;
    PlayerId getId() const { return id; }

private:
    PlayerId id;
    // Board *board; // to be used later, when implementing strategies
};

#endif // PLAYER_HPP