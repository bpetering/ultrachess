#include "moves.h"


Move::Move() {
    src.file = dst.file = '?';
    src.rank = dst.rank = 0;
    piece = '?';
    did_capture = false;
    did_check = false;
    did_checkmate = false;
}

void Move::make_explicit() {

}
