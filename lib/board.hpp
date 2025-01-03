#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

class Board
{
public:
    Board();
    bool makeMove(int row, int col, char player);
    bool checkWin(char player) const;
    bool isFull() const;
    void display() const;

private:
    std::vector<std::vector<char>> board;

    bool checkRow(int row, char player) const;
    bool checkCol(int col, char player) const;
    bool checkDiagonals(char player) const;
};

#endif // BOARD_HPP