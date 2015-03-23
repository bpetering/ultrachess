#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "pieces.h"

#include <ctime>

class Turn {
    player_t player;
    double started_at_secs;
public:
    Turn(player_t c, double s) : player(c), started_at_secs(s) {}
};

class Game {
    Board board;
    Piece pieces[32];       // in case removed from board
    int pidx;
    double elapsed_secs;
    double white_turn_secs;
    double black_turn_secs;
    list<Turn> turn_history;
public:
    Game();
    void init();
    void create_piece(player_t, Piece, char, int);
};

#endif
