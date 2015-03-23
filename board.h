#ifndef BOARD_H
#define BOARD_H

#include "boardref.h"
#include "pieces.h"

class Board {
public:
    map<BoardRef, Piece*> squares;

    Board();
};

#endif
