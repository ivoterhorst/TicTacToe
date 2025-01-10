#include "lib/game.hpp"
#include "lib/board.hpp"
#include "lib/player.hpp"
#include "lib/types.hpp"

#include <memory>

int main(int argc, char **argv)
{
    std::shared_ptr<Board> board = std::make_shared<Board>();
    // std::shared_ptr<Player> player1 = std::make_shared<Player>(PlayerId::X, board.get());
    // std::shared_ptr<Player> player2 = std::make_shared<Player>(PlayerId::O, board.get());
    std::shared_ptr<Player> player1 = std::make_shared<Player>(PlayerId::X);
    std::shared_ptr<Player> player2 = std::make_shared<Player>(PlayerId::O);

    Game game(board, player1, player2);
    game.play();

    board.reset();
    player1.reset();
    player2.reset();
}