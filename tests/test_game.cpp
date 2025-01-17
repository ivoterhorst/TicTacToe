#include <gtest/gtest.h>

#include "lib/game.hpp"
#include "lib/board.hpp"
#include "playerchooser_mock.hpp"
#include "lib/startingplayerchooser.hpp"
#include "player_mock.hpp"

TEST(GameAssertions, FirstTest)
{
  std::shared_ptr<Board> board = std::make_shared<Board>();
  std::shared_ptr<Player> player1 = std::make_shared<PlayerMock>(PlayerId::X);
  std::shared_ptr<Player> player2 = std::make_shared<PlayerMock>(PlayerId::O);
  std::shared_ptr<StartingPlayerChooser> startingPlayerChooser = std::make_shared<PlayerChooserMock>();

  Game game = Game(board, player1, player2, startingPlayerChooser);
  PlayerMock *player1Mock = dynamic_cast<PlayerMock *>(player1.get());
  PlayerMock *player2Mock = dynamic_cast<PlayerMock *>(player2.get());
  PlayerChooserMock *startingPlayerChooserMock = dynamic_cast<PlayerChooserMock *>(startingPlayerChooser.get());

  EXPECT_CALL(*startingPlayerChooserMock, chooseStartingPlayer())
      .WillOnce(testing::Return(PlayerId::X));

  EXPECT_CALL(*player1Mock, getMove())
      .WillOnce(testing::Return(Move{0, 0}))
      .WillOnce(testing::Return(Move{0, 1}))
      .WillOnce(testing::Return(Move{0, 2}));
  EXPECT_CALL(*player2Mock, getMove())
      .WillOnce(testing::Return(Move{1, 0}))
      .WillOnce(testing::Return(Move{1, 1}));
  game.play();

  board.reset();
  player1.reset();
  player2.reset();
  startingPlayerChooser.reset();
}
