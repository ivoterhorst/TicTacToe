#include "lib/game.hpp"
#include "lib/board.hpp"
#include "lib/humanplayer.hpp"
#include "lib/types.hpp"
#include "lib/startingplayerchooser.hpp"
#include "lib/randomplayerchooser.hpp"

#include <memory>

int main(int argc, char **argv)
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    // std::shared_ptr<Player> player1 = std::make_shared<Player>(PlayerId::X, board.get());
    // std::shared_ptr<Player> player2 = std::make_shared<Player>(PlayerId::O, board.get());
    std::shared_ptr<Player> player1 = std::make_shared<HumanPlayer>(PlayerId::X);
    std::shared_ptr<Player> player2 = std::make_shared<HumanPlayer>(PlayerId::O);
    std::shared_ptr<StartingPlayerChooser> startingPlayerChooser = std::make_shared<RandomStartingPlayerChooser>();

    Game game(board, player1, player2, startingPlayerChooser);
    game.play();

    board.reset();
    player1.reset();
    player2.reset();
    startingPlayerChooser.reset();
}