#include <gtest/gtest.h>

#include "lib/board.hpp"

TEST(EmptyBoard, BasicAssertions) {
  // new board should be empty
    Board board;
    EXPECT_FALSE(board.checkWin('X'));
}