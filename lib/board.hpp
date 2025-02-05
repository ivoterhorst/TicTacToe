#pragma once

#include <vector>
#include <string>

#include "types.hpp"

using tictactoe::Move;
using tictactoe::PlayerId;

class Board
{
public:
    Board();
    bool makeMove(Move move, PlayerId player);
    bool checkWin(PlayerId player) const;
    bool isFull() const;
    void display() const;

private:
    std::vector<std::vector<PlayerId>> board;

    bool checkRow(int row, PlayerId player) const;
    bool checkCol(int col, PlayerId player) const;
    bool checkDiagonals(PlayerId player) const;
};
