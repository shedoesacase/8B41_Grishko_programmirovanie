#include <gtest/gtest.h>
#include "../tasks/task3.hpp"
#include "../tasks/task4.hpp"
#include "../tasks/task6.hpp"
#include "../tasks/task7.hpp"

TEST(Task3, SimpleEquation) {
    EXPECT_EQ(solution("x=5"), "x=5");
    EXPECT_EQ(solution("2x=4"), "x=2");
    EXPECT_EQ(solution("x+2x+1-2=6+x-1"), "x=3");
}

TEST(Task3, NoSolution) {
    EXPECT_EQ(solution("0x=5"), "NO");
}

TEST(Task3, InfiniteSolutions) {
    EXPECT_EQ(solution("x=x"), "Infinite");
}

TEST(Task4, Basic) {
    std::vector<std::string> input = {"10:10", "12:23", "23:55", "00:23"};
    EXPECT_EQ(timediff(input, 3, 2), 28);
}

TEST(Task4, minDif) {
    std::vector<std::string> input = {"00:00", "23:59"};
    EXPECT_EQ(timediff(input, 0, 1), 1);
}

TEST(Task4, Sametime) {
    std::vector<std::string> input = {"11:11", "11:11"};
    EXPECT_EQ(timediff(input, 1, 0), 0);
}

TEST(Task6, Basic){
    EXPECT_EQ(primer("   3  +  2"), 5);
}
TEST(Task6, Harder){
    EXPECT_EQ(primer("(  3     +  5)  -    2"), 6);
}
TEST(Task6, Hardest){
    EXPECT_EQ(primer("3   +   5 -  (2   +   4)  +   7"), 9);
}

TEST(Task7, small){
    EXPECT_EQ(begin(5),5 );
}
TEST(Task7, big){
    EXPECT_EQ(begin(12),8 );
}
TEST(Task7, bigger){
    EXPECT_EQ(begin(20),12);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    std::cin.ignore();
    return 0;
}