#include "../unittest-cpp/src/UnitTest++.h"
#include "../boardref.h"

TEST(CreateStringify) {
    BoardRef ref;
    ref.file = 'a';
    ref.rank = 1;
    CHECK(ref.file == 'a');
    CHECK(ref.rank == 1);
    CHECK(ref.to_string() == "a1");

    BoardRef ref2 ('h', 8);
    CHECK(ref2.file == 'h');
    CHECK(ref2.rank == 8);
    CHECK(ref2.to_string() == "h8");

    BoardRef ref3 ("c4");
    CHECK(ref3.file == 'c');
    CHECK(ref3.rank == 4);
    CHECK(ref3.to_string() == "c4");
}

TEST(Compare) {
    BoardRef r1, r2;
    CHECK(r1 == r2);

    BoardRef r3('a', 1);
    BoardRef r4("a1");
    CHECK(r3 == r4);
    CHECK(r3 != r1);
    CHECK(r4 != r2);

    BoardRef r5('c', 6);
    CHECK(r5 != r3);

    BoardRef r6('c', 7);
    CHECK(r5 != r6);

    BoardRef r7('a', 2);
    CHECK(r7 != r3);
}

int main() {
    return UnitTest::RunAllTests();
}
