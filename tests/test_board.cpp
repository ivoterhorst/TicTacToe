#include <gtest/gtest.h>

#include "lib/board.hpp"

TEST(BoardAssertions, EmptyBoard)
{
  // new board should be empty
  Board board;
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, FirstMove)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, FirstRowX)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(0, 1, 'X');
  board.makeMove(0, 2, 'X');
  EXPECT_TRUE(board.checkWin('X'));
}

TEST(BoardAssertions, FirstRowMixed)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(0, 1, 'O');
  board.makeMove(0, 2, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, FirstColX)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(1, 0, 'X');
  board.makeMove(2, 0, 'X');
  EXPECT_TRUE(board.checkWin('X'));
}

TEST(BoardAssertions, FirstColMixed)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(1, 0, 'O');
  board.makeMove(2, 0, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, LastRowX)
{
  // new board should be empty
  Board board;
  board.makeMove(2, 0, 'X');
  board.makeMove(2, 1, 'X');
  board.makeMove(2, 2, 'X');
  EXPECT_TRUE(board.checkWin('X'));
}

TEST(BoardAssertions, LastRowMixed)
{
  // new board should be empty
  Board board;
  board.makeMove(2, 0, 'X');
  board.makeMove(2, 1, 'O');
  board.makeMove(2, 2, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, LastColX)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 2, 'X');
  board.makeMove(1, 2, 'X');
  board.makeMove(2, 2, 'X');
  EXPECT_TRUE(board.checkWin('X'));
}

TEST(BoardAssertions, LastColMixed)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 2, 'X');
  board.makeMove(1, 2, 'O');
  board.makeMove(2, 2, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, DiagonalX)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(1, 1, 'X');
  board.makeMove(2, 2, 'X');
  EXPECT_TRUE(board.checkWin('X'));
}

TEST(BoardAssertions, DiagonalMixed)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(1, 1, 'O');
  board.makeMove(2, 2, 'X');
  EXPECT_FALSE(board.checkWin('X'));
}

TEST(BoardAssertions, FullBoard)
{
  // new board should be empty
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(0, 1, 'O');
  board.makeMove(0, 2, 'X');
  board.makeMove(1, 0, 'X');
  board.makeMove(1, 1, 'O');
  board.makeMove(1, 2, 'X');
  board.makeMove(2, 0, 'X');
  board.makeMove(2, 1, 'O');
  board.makeMove(2, 2, 'X');
  EXPECT_TRUE(board.isFull());
  EXPECT_TRUE(board.checkWin('X'));
  EXPECT_TRUE(board.checkWin('O'));
}

TEST(BoardAssertions, InvalidMove)
{
  Board board;
  board.makeMove(0, 0, 'X');
  EXPECT_FALSE(board.makeMove(0, 0, 'O'));
  EXPECT_FALSE(board.makeMove(0, 0, ' '));
  EXPECT_FALSE(board.makeMove(0, 0, 'X'));
}

TEST(BoardAssertions, OutOfBounds)
{
  Board board;
  EXPECT_FALSE(board.makeMove(-1, 0, 'X'));
  EXPECT_FALSE(board.makeMove(0, -1, 'X'));
  EXPECT_FALSE(board.makeMove(3, 0, 'X'));
  EXPECT_FALSE(board.makeMove(0, 3, 'X'));
}

TEST(BoardAssertions, Display)
{
  Board board;
  board.makeMove(0, 0, 'X');
  board.makeMove(0, 1, 'O');
  board.makeMove(0, 2, 'X');
  board.makeMove(1, 0, 'X');
  board.makeMove(1, 1, 'O');
  board.makeMove(1, 2, 'X');
  board.makeMove(2, 0, 'X');
  board.makeMove(2, 1, 'O');
  board.makeMove(2, 2, 'X');
  testing::internal::CaptureStdout();
  board.display();
  std::string output = testing::internal::GetCapturedStdout();
  std::string expected = "X O X \nX O X \nX O X \n";
  EXPECT_EQ(output, expected);
}