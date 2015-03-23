#include "pieces.h"

Piece::Piece() {}

list<BoardRef> Pawn::traversed_refs(BoardRef ref) {
    list<BoardRef> ret;
    int diff = current.rank - ref.rank;
    int sign;
    if (diff < 0)
        sign = 1;
    else
        sign = -1;
    for (int i = 1; i <= diff; i++) {
        BoardRef next (current.file, current.rank + (sign * i));
        ret.push_back(next);
    }
    return ret;
}

bool Pawn::is_legal_move(BoardRef ref) {
    unsigned int max_traverse = 1;

    if (current == ref)     // not a move
        return false;
    if (move_history.size() == 0)
        max_traverse = 2;
    // TODO capture, en-passant etc
    if (current.file != ref.file) {
        return false;
    }

    list<BoardRef> traversed = traversed_refs(ref);
    if (traversed.size() > max_traverse)
        return false;
    // Is there a piece in the way that we're not capturing?

    return true;
}
