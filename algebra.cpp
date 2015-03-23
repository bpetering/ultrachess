#include "algebra.h"
#include "macros.h"

#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;


#define skip_space() while(isspace(s[pos])) pos++;

string SANParser::move_marker_string(int n) {
    string move_marker;
    ostringstream oss;

    oss << n;
    move_marker = oss.str();
    move_marker += ".";
    return move_marker;
}

Move SANParser::parse_single_move(string s, player_t c) {
    size_t pos = 0;
    size_t len = s.size();
    Move move;
    bool used_src = false;

    move.player = c;
    while (pos < len) {
        skip_space();
        if (is_piece(s[pos]))
            move.piece = s[pos];
        if (is_file(s[pos])) {
            if (used_src)
                move.dst.file = s[pos];
            else
                move.src.file = s[pos];
        }
        if (is_rank(s[pos])) {
            if (used_src)
                move.dst.rank = digit_to_int(s[pos]);
            else {
                move.src.rank = digit_to_int(s[pos]);
                used_src = true;
            }
        }
        if (is_capture(s[pos]))
            move.did_capture = true;
        if (is_check(s[pos]))
            move.did_check = true;
        pos++;
    }
    return move;
}

list<Move> SANParser::extract_moves(string s) {
    list<Move> moves;
    size_t pos = 0;
    size_t end_pos = 0;
    size_t len = s.size();
    string tmp;
    bool seen_white = false;
    player_t player = white;

    while (pos < len) {
        Move m;

        skip_space();
        end_pos = pos;
        while (end_pos < len && !isspace(s[end_pos]))
            end_pos++;
        tmp = s.substr(pos, end_pos - pos);

        if (seen_white)
            player = black;
        m = parse_single_move(tmp, player);
        seen_white = true;

        pos = end_pos;
    }
}

list<Move> SANParser::parse_string(string s) {
    int move_number = 1;
    size_t pos, next_pos;
    size_t len = s.size();
    string mma, mmb;

    do {
        // Update our marker offsets
        mma = move_marker_string(move_number);
        mmb = move_marker_string(move_number + 1);
        pos = s.find(mma);
        next_pos = s.find(mmb);
        if (next_pos == string::npos)
            next_pos = len;

        // Handle text between markers
        pos += 2;


        move_number++;
    } while (next_pos != len);
}

//void SANParser::make_explicit();

int main() {
    SANParser parser;
    string input;

    while (input != "exit") {
        cout << "Enter move: ";
        cin >> input;
        Move m = parser.parse_single_move(input, white);
        cout << "src: " << m.src.to_string() << endl;
        cout << "dst: " << m.dst.to_string() << endl;
        cout << "piece: " << m.piece << endl;
        cout << "player: " << m.player << endl;
        if (m.did_capture)
            cout << "(capture)" << endl;
        if (m.did_check)
            cout << "(check)" << endl;
        cout << endl;
    }
}
