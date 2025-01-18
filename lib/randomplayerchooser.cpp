#include "lib/startingplayerchooser.hpp"
#include "lib/randomplayerchooser.hpp"
#include "lib/types.hpp"

#include <ctime>

PlayerId RandomStartingPlayerChooser::chooseStartingPlayer()
{
    std::srand(std::time(nullptr));                            // seed random number generator with current time
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