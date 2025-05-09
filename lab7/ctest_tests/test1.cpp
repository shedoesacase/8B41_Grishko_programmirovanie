#include <cassert>
#include "../tasks/task2.hpp"

void test_case_1() {
    assert(canReach(2, 3, 4, 7, 10) == true);
}

int main() {
    test_case_1();
    return 0;
}
