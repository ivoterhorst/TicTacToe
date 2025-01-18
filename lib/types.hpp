#pragma once
#include <ostream>

struct Move
{
    int row;
    int col;
};

class PlayerId
{
public:
    enum Value
    {
        X,
        O,
        None,
    };

    PlayerId() = default;
    constexpr PlayerId(Value playerId) : value(playerId) {}

    // #if Enable switch (playerId) use case:
    //     // Allow switch and comparisons.
    //     constexpr operator Value() const { return value; }

    //     // Prevent usage: if(playerId)
    //     explicit operator bool() const = delete;
    // #else
    constexpr bool operator==(PlayerId a) const { return value == a.value; }
    constexpr bool operator!=(PlayerId a) const { return value != a.value; }
    // #endif

    friend std::ostream &operator<<(std::ostream &os, const PlayerId &playerId)
    {
        os << playerId.ToChar();
        return os;
    }

private:
    Value value;

    constexpr char ToChar() const
    {
        if (value == X)
            return 'X';
        if (value == O)
            return 'O';
        return ' ';
    }
};