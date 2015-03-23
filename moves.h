#ifndef MOVES_H
#define MOVES_H

#include "pieces.h"
#include "board.h"

// Represent a move, abstractly
class Move {
public:
    // Not all needed at once - just enough to be unambiguous
    BoardRef src;
    BoardRef dst;
    player_t player;
    char piece;
    bool did_capture;
    bool did_check;
    bool did_checkmate;

    Move();
    void make_explicit();
};

#endif
