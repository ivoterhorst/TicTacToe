#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
public:
    Board();
    bool makeMove(int row, int col, char player);
    bool checkWin(char player) const;
    bool isFull() const;

private:
    char board[3][3];
    bool checkRow(int row) const;
    bool checkCol(int col) const;
    bool checkDiagonals() const;
};

#endif // BOARD_HPP