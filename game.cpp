#include "game.h"

extern char files[8];
extern int  ranks[8];

Game::Game() {
    pidx = 0;
}

void Game::create_piece(player_t pt, Piece p, char file, int rank) {
    BoardRef ref (file, rank);
    p.current = ref;
    p.player = pt;
    board.squares[ref] = p;
    pieces[pidx++] = p;
}

void Game::init() {
    // Create white pieces
    {
        for (int j = 0; j < 8; j++) {
            Pawn pawn;
            create_piece(white, pawn, files[j], 2);
        }
        Rook r1, r2;
        create_piece(white, r1, 'a', 1);
        create_piece(white, r2, 'h', 1);
        Knight k1, k2;
        create_piece(white, k1, 'b', 1);
        create_piece(white, k2, 'g', 1);
        Bishop b1, b2;
        create_piece(white, b1, 'c', 1);
        create_piece(white, b2, 'f', 1);
        Queen q;
        create_piece(white, q, 'd', 1);
        King k;
        create_piece(white, k, 'e', 1);
    }

    // Create black pieces
    {
        for (int j = 0; j < 8; j++) {
            Pawn pawn;
            create_piece(black, pawn, files[j], 7);
        }
        Rook r1, r2;
        create_piece(black, r1, 'a', 8);
        create_piece(black, r2, 'h', 8);
        Knight k1, k2;
        create_piece(black, k1, 'b', 8);
        create_piece(black, k2, 'g', 8);
        Bishop b1, b2;
        create_piece(black, b1, 'c', 8);
        create_piece(black, b2, 'f', 8);
        Queen q;
        create_piece(black, q, 'd', 8);
        King k;
        create_piece(black, k, 'e', 8);
    }
}

void Game::start() {
    // TODO set time
    // update turn history
}
