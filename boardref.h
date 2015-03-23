#ifndef BOARDREF_H
#define BOARDREF_H

#include <map>
#include <string>

using namespace std;

const char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
const int  ranks[8] = {1, 2, 3, 4, 5, 6, 7, 8};

class BoardRef {
public:
    char file;
    int rank;

    BoardRef();
    BoardRef(string);
    BoardRef(char, int);
    string to_string();
    bool operator == (const BoardRef&);
};

#endif
