#include <gtest/gtest.h>

#include "lib/board.hpp"

TEST(BoardAssertions, EmptyBoard)
{
  // new board should be empty
  Board board;
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, EmptyBoard_FirstMove)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, EmptyBoard_FirstRow)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(0, 1, 'X');
  board.makeMove(0, 2, 'X');
  EXPECT_TRUE(board.checkWin('X'));
}