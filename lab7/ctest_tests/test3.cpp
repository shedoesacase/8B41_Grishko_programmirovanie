#include <cassert>
#include "../tasks/task2.hpp"

void test_case_3() {
    assert(canReach(10, 5, 35, 20, 27) == true);
}

int main() {
    test_case_3();
    return 0;
}
