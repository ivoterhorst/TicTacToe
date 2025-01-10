#include <string>
#include "types.hpp"
#include "utils.hpp"

std::string playerIdToString(PlayerId playerId)
{
    switch (playerId)
    {
    case PlayerId::X:
        return "X";
    case PlayerId::O:
        return "O";
    case PlayerId::None:
        return " ";
    default:
        return " ";
    }
}