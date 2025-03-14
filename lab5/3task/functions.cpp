#include <iostream>
#include "functions.h"

// Шестая функция (верхняя в стеке вызовов)
void func6() {
    std::cout << "func6: Начало выполнения" << std::endl;
    // Выбрасываем исключение типа double
    throw 52.42;
    std::cout << "func6: Конец выполнения" << std::endl; // Этот код не выполнится
}

// Пятая функция
void func5() {
    std::cout << "func5: Начало выполнения" << std::endl;
    func6(); // Вызываем func6
    std::cout << "func5: Конец выполнения" << std::endl;
}

// Четвёртая функция
void func4() {
    std::cout << "func4: Начало выполнения" << std::endl;
    try {
        func5(); // Вызываем func5
    } catch (int e) {
        std::cout << "func4: Поймано исключение типа int со значением " << e << std::endl;
    }
    std::cout << "func4: Конец выполнения" << std::endl;
}

// Третья функция
void func3() {
    std::cout << "func3: Начало выполнения" << std::endl;
    try {
        func4(); // Вызываем func4
    } catch (int e) {
        std::cout << "func3: Поймано исключение типа int со значением " << e << std::endl;
    } catch (double e) { //тут будет ловиться исключение из func6
        std::cout << "func3: Поймано исключение типа double со значением " << e << std::endl;
    }
    std::cout << "func3: Конец выполнения" << std::endl;
}

// Вторая функция
void func2() {
    std::cout << "func2: Начало выполнения" << std::endl;
    func3(); // Вызываем func3
    std::cout << "func2: Конец выполнения" << std::endl;
}