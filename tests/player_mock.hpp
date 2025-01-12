#include <gmock/gmock.h>

#include "lib/player.hpp"

class PlayerMock : public Player
{
public:
    PlayerMock(PlayerId id) : Player(id) {}
    MOCK_CONST_METHOD0(getMove, Move());
};
