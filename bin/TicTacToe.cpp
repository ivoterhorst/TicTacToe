#include "lib/board.hpp"

int main(int argc, char **argv)
{
    Board board;
    board.makeMove(0, 0, 'X');
    board.makeMove(1, 1, 'O');
    board.makeMove(2, 2, 'X');
    board.display();
}