#include <gtest/gtest.h>

#include "lib/board.hpp"

TEST(BoardAssertions, EmptyBoard)
{
  // new board should be empty
  Board board;
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, FirstMove)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, FirstRowX)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({0, 1}, PlayerId::X);
  board.makeMove({0, 2}, PlayerId::X);
  EXPECT_TRUE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, FirstRowMixed)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({0, 1}, PlayerId::O);
  board.makeMove({0, 2}, PlayerId::X);
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, FirstColX)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({1, 0}, PlayerId::X);
  board.makeMove({2, 0}, PlayerId::X);
  EXPECT_TRUE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, FirstColMixed)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({1, 0}, PlayerId::O);
  board.makeMove({2, 0}, PlayerId::X);
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, LastRowX)
{
  // new board should be empty
  Board board;
  board.makeMove({2, 0}, PlayerId::X);
  board.makeMove({2, 1}, PlayerId::X);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_TRUE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, LastRowMixed)
{
  // new board should be empty
  Board board;
  board.makeMove({2, 0}, PlayerId::X);
  board.makeMove({2, 1}, PlayerId::O);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, LastColX)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 2}, PlayerId::X);
  board.makeMove({1, 2}, PlayerId::X);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_TRUE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, LastColMixed)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 2}, PlayerId::X);
  board.makeMove({1, 2}, PlayerId::O);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, DiagonalX)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({1, 1}, PlayerId::X);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_TRUE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, DiagonalMixed)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({1, 1}, PlayerId::O);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_FALSE(board.checkWin(PlayerId::X));
}

TEST(BoardAssertions, FullBoard)
{
  // new board should be empty
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({0, 1}, PlayerId::O);
  board.makeMove({0, 2}, PlayerId::X);
  board.makeMove({1, 0}, PlayerId::X);
  board.makeMove({1, 1}, PlayerId::O);
  board.makeMove({1, 2}, PlayerId::X);
  board.makeMove({2, 0}, PlayerId::X);
  board.makeMove({2, 1}, PlayerId::O);
  board.makeMove({2, 2}, PlayerId::X);
  EXPECT_TRUE(board.isFull());
  EXPECT_TRUE(board.checkWin(PlayerId::X));
  EXPECT_TRUE(board.checkWin(PlayerId::O));
}

TEST(BoardAssertions, InvalidMove)
{
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  EXPECT_FALSE(board.makeMove({0, 0}, PlayerId::O));
  EXPECT_FALSE(board.makeMove({0, 0}, PlayerId::None));
  EXPECT_FALSE(board.makeMove({0, 0}, PlayerId::X));
}

TEST(BoardAssertions, OutOfBounds)
{
  Board board;
  EXPECT_FALSE(board.makeMove({-1, 0}, PlayerId::X));
  EXPECT_FALSE(board.makeMove({0, -1}, PlayerId::X));
  EXPECT_FALSE(board.makeMove({3, 0}, PlayerId::X));
  EXPECT_FALSE(board.makeMove({0, 3}, PlayerId::X));
  EXPECT_FALSE(board.makeMove({'a', 'b'}, PlayerId::X));
}

TEST(BoardAssertions, Display)
{
  Board board;
  board.makeMove({0, 0}, PlayerId::X);
  board.makeMove({0, 1}, PlayerId::O);
  board.makeMove({0, 2}, PlayerId::X);
  board.makeMove({1, 0}, PlayerId::X);
  board.makeMove({1, 1}, PlayerId::O);
  board.makeMove({1, 2}, PlayerId::X);
  board.makeMove({2, 0}, PlayerId::X);
  board.makeMove({2, 1}, PlayerId::O);
  board.makeMove({2, 2}, PlayerId::X);
  testing::internal::CaptureStdout();
  board.display();
  std::string output = testing::internal::GetCapturedStdout();
  std::string expected = "X O X \nX O X \nX O X \n";
  EXPECT_EQ(output, expected);
}