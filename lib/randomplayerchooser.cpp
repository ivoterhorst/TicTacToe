#include "lib/startingplayerchooser.hpp"
#include "lib/randomplayerchooser.hpp"
#include "lib/types.hpp"

#include <ctime>
#include <iostream>

RandomStartingPlayerChooser::RandomStartingPlayerChooser()
{
    // Seed random number generator with current time
    // Make sure to reuse same instance for all calls to chooseStartingPlayer to avoid same
    // seed in case of multiple calls in quick succession.
    std::srand(std::time(0)); // seed random number generator with current time
};

PlayerId RandomStartingPlayerChooser::chooseStartingPlayer()
{
    int zeroOrOne = (1 + std::rand()) / ((RAND_MAX + 1u) / 2); // Note: 1 + rand() % sides is biased
    if (zeroOrOne == 0)
    {
        return PlayerId::X;
    }
    else
    {
        return PlayerId::O;
    }
};