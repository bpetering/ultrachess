#ifndef ALGEBRA_H
#define ALGEBRA_H

#include "moves.h"

#include <string>
#include <list>

using namespace std;

class SANParser {
public:
    SANParser() {}
    string move_marker_string(int);
    Move parse_single_move(string, player_t);
    list<Move> extract_moves(string);
    list<Move> parse_string(string);
};

#endif
