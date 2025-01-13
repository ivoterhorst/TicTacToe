#include <iostream>
#include <vector>
#include <string>

#include "board.hpp"
#include "types.hpp"

Board::Board() : board(3, std::vector<PlayerId>(3, PlayerId::None)) {}

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

bool Board::makeMove(Move move, PlayerId player)
{
    if (move.row < 0 || move.row >= 3 || move.col < 0 || move.col >= 3 || board[move.row][move.col] != PlayerId::None)
    {
        return false;
    }
    board[move.row][move.col] = player;
    return true;
}

bool Board::checkWin(PlayerId player) const
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
            if (cell == PlayerId::None)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkRow(int row, PlayerId player) const
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

bool Board::checkCol(int col, PlayerId player) const
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

bool Board::checkDiagonals(PlayerId player) const
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