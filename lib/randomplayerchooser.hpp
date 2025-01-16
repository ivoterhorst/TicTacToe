#pragma once

#include "startingplayerchooser.hpp"

#include "lib/startingplayerchooser.hpp"
#include "lib/types.hpp"

class RandomStartingPlayerChooser : public StartingPlayerChooser
{
public:
    PlayerId chooseStartingPlayer() override;
};