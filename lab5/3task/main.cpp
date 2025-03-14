#include <iostream>
#include "functions.h"

// Первая функция (main)
int main() {
    std::cout << "main: Начало выполнения" << std::endl;
    try {
        func2(); // Вызываем func2
    } catch (...) {
        std::cout << "main: Поймано необработанное исключение" << std::endl;
    }
    std::cout << "main: Конец выполнения" << std::endl;
    return 0;
}