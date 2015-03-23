#include "boardref.h"
#include "macros.h"

BoardRef::BoardRef() {}

BoardRef::BoardRef(string string_ref) {
    char file = string_ref[0];
    int rank = digit_to_int(string_ref[1]);
}

BoardRef::BoardRef(char file, int rank) : file(file), rank(rank) {}

string BoardRef::to_string() {
    string ret;
    char r = int_to_digit(rank);
    ret.append(1, file);
    ret.append(1, r);
    return ret;
}

bool BoardRef::operator == (const BoardRef& other) {
    if (file == other.file && rank == other.rank)
        return true;
    return false;
}

