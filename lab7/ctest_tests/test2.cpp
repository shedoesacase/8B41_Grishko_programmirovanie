#include <cassert>
#include "../tasks/task2.hpp"

void test_case_2() {
    assert(canReach(2, 3, 4, 7, 1) == false);
}

int main() {
    test_case_2();
    return 0;
}
