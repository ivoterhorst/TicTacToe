#pragma once

#include "startingplayerchooser.hpp"

#include "lib/startingplayerchooser.hpp"
#include "lib/types.hpp"

using tictactoe::PlayerId;

class RandomStartingPlayerChooser : public StartingPlayerChooser
{
public:
    RandomStartingPlayerChooser();
    PlayerId chooseStartingPlayer() override;
};