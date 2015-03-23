#ifndef PIECE_H
#define PIECE_H

#include "boardref.h"

#include <list>

using namespace std;


enum player_t { white, black };

class Piece {
protected:
    bool is_captured;
    list<BoardRef> move_history;
public:
    player_t player;
    BoardRef current;

    Piece();
    Piece(player_t p, BoardRef r) : player(p), current(r) {}
    void move(string);
    virtual list<BoardRef> traversed_refs(BoardRef) = 0;
    virtual bool is_legal_move(BoardRef) = 0;
    virtual ~Piece() {}     // avoid resource leaks - how?
};

class Pawn : public Piece {
public:
    Pawn();
    Pawn(player_t p, BoardRef r) : Piece(p, r) {}
    bool is_legal_move(BoardRef);
    list<BoardRef> traversed_refs(BoardRef);
};

class Rook : public Piece {};

class Knight : public Piece {};

class Bishop : public Piece {};

class Queen : public Piece {};

class King : public Piece {};


#endif
