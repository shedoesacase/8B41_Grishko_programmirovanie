#include <cassert>
#include "../tasks/task1.hpp"
#include <iostream>
int main(){
    assert(position(3, 0) == 1 && "Test 1 failed");
    std::cout << "Тест 1 (3, 0 == 1) пройден" << std::endl;
    assert(position(10, 15) == 4 && "Test 2 failed");
    std::cout << "Тест 2 (10, 15 == 4) пройден" << std::endl;
    assert(position(5, 4) == 5 && "Test 3 failed");
    std::cout << "Тест 3 (5, 4 == 5) пройден" << std::endl;

    std::cout << "Тесты пройдены";
    return 0;
}