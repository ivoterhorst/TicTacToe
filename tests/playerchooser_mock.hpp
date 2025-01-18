#include <gmock/gmock.h>

#include "lib/startingplayerchooser.hpp"

class PlayerChooserMock : public StartingPlayerChooser
{
public:
    MOCK_METHOD(PlayerId, chooseStartingPlayer, (), (override));
};
