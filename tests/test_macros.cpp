#include "../unittest-cpp/src/UnitTest++.h"
#include "../macros.h"

TEST(DigitToInt) {
    CHECK(digit_to_int('0') == 0);
    CHECK(digit_to_int('9') == 9);
}

TEST(IntToDigit) {
    CHECK(int_to_digit(0) == '0');
    CHECK(int_to_digit(9) == '9');
}

TEST(IsFile) {
    CHECK(!is_file('a'-1));
    CHECK(!is_file('h'+1));
    CHECK(is_file('a'));
    CHECK(is_file('h'));
    CHECK(!is_file('A'));
    CHECK(!is_file('H'));
    CHECK(!is_file('0'));
}

TEST(IsRank) {
    CHECK(!is_rank('0'));
    CHECK(!is_rank('9'));
    CHECK(is_rank('1'));
    CHECK(is_rank('8'));
    CHECK(!is_rank('a'));
    CHECK(!is_rank('A'));
}

TEST(IsPiece) {
    CHECK(!is_piece('P'));
    CHECK(!is_piece('X'));
    CHECK(!is_piece('0'));
    CHECK(!is_piece('a'));
    CHECK(!is_piece('h'));
    CHECK(is_piece('K'));
    CHECK(is_piece('Q'));
    CHECK(is_piece('R'));
    CHECK(is_piece('B'));
    CHECK(is_piece('N'));
}

TEST(IsCapture) {
    CHECK(!is_capture('!'));
    CHECK(is_capture('x'));
    CHECK(is_capture(':'));
}

TEST(IsCheck) {
    CHECK(!is_check('@'));
    CHECK(is_check('+'));
}

int main() {
    return UnitTest::RunAllTests();
}
