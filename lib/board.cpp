#include <iostream>
#include <vector>

#include "board.hpp"

Board::Board() : board(3, std::vector<char>(3, ' ')) {}

void Board::display() const
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::makeMove(int row, int col, char player)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
    {
        return false;
    }
    board[row][col] = player;
    return true;
}

bool Board::checkWin(char player) const
{
    for (int i = 0; i < 3; ++i)
    {
        if (checkRow(i, player) || checkCol(i, player))
        {
            return true;
        }
    }
    return checkDiagonals(player);
}

bool Board::isFull() const
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkRow(int row, char player) const
{
    for (int col = 0; col < 3; ++col)
    {
        if (board[row][col] != player)
        {
            return false;
        }
    }
    return true;
}

bool Board::checkCol(int col, char player) const
{
    for (int row = 0; row < 3; ++row)
    {
        if (board[row][col] != player)
        {
            return false;
        }
    }
    return true;
}

bool Board::checkDiagonals(char player) const
{
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] != player)
        {
            diag1 = false;
        }
        if (board[i][2 - i] != player)
        {
            diag2 = false;
        }
    }
    return diag1 || diag2;
}