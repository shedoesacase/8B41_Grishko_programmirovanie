#include <iostream>
#include <ctime>
#include "matrix.hpp"
#include "square_matrix.hpp"
#include <stdexcept>
#include <cstdlib>


int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Matrix matd; // Создаем объект матрицы с помощью дефолтного конструктора
    std::cout << "Default Matrix output 1:" << std::endl;
    std::cout << matd << std::endl; // Выводим матрицу

    int a, b, c, d;
    std::cout << "Введите количество строк и столбцов" << std::endl;
    std:: cin >> a >> b >> c >> d;

    /////////////////////////////////////////////////////////////////////
    Matrix mat1(a, b); // Создаем объект матрицы с помощью недефолтного конструктора
    std::cout << "Custom Matrix output 1:" << std::endl;
    std::cout << mat1 << std::endl; // Выводим матрицу

    Matrix mat2(c, d); // Создаем объект матрицы с помощью недефолтного конструктора
    std::cout << "Custom Matrix output 2:" << std::endl;
    std::cout << mat2 << std::endl; // Выводим матрицу

    /////////////////////////////////////////////////////////////////////
    try { //Блок кода, отвечающий за попытку сложить матрицы
        Matrix matplus = mat1 + mat2;
        std::cout << "Результат сложения" << std::endl;
        std::cout << matplus  << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    /////////////////////////////////////////////////////////////////////
    try { //Блок кода, отвечающий за попытку вычесть матрицы
        Matrix matminus = mat1 - mat2;
        std::cout << "результат вычитания:" << std::endl;
        std::cout << matminus << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    /////////////////////////////////////////////////////////////////////
    //Умножение матрицы на число
    int num;
    std::cout << "Введите число, на которое умножится первая матрица:" <<std::endl;
    std::cin >> num;
    Matrix matnum = mat1 * num;
    std::cout << "Результат умножения матрицы на число" << std::endl << matnum << std::endl;
    
    /////////////////////////////////////////////////////////////////////
    try { //Блок кода, отвечающий за попытку умножить матрицы
        Matrix matxmat = mat1 * mat2;
        std::cout << "результат умножения матриц:" << std::endl;
        std::cout << matxmat << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    /////////////////////////////////////////////////////////////////////
    std::cout << "Попытка сравнить матрицы:" << std::endl;
    if(mat1 == mat2) std::cout << "Матрицы равны" << std::endl << std::endl;
    else std::cout << "Матрицы не равны" <<std::endl << std::endl;

    /////////////////////////////////////////////////////////////////////
    std::cout << "Приравниваем mat1 к mat2 и пробуем сравнить заново:" << std::endl;
    mat1 = mat2;
    std::cout << "Матрица 1:" <<std::endl << mat1 << std::endl << "Новая матрица 2:" << std::endl << mat2 << std::endl;
    if(mat1 == mat2) std::cout << "Матрицы равны" << std::endl;
    else std::cout << "Матрицы не равны" <<std::endl << std::endl;
    /////////////////////////////////////////////////////////////////////
    std::cout << "Максимальный элемент матрицы 1 равен: " << mat1.max() << std::endl;

    /////////////////////////////////////////////////////////////////////
    Matrix matinput(2, 2);
    std::cout << "Проверка возможности вводить матрицы пользователем (размер матрицы - 2 на 2). Введите значения для матрицы:" <<std::endl;
    std::cin >> matinput;
    std::cout << "Введенная матрица:" << std::endl << matinput;

    /////////////////////////////////////////////////////////////////////
    SquareMatrix sqmat(3);
    std::cout << "Квадратная матрица с размерностью 3:" << std::endl << sqmat;
    
    //////////////////////////////////////////////////////////////////////
    std::cout << "Определитель матрицы: " << sqmat.determinant() << std::endl;

    //////////////////////////////////////////////////////////////////////
    std::cout << "Проверка симметричности матрицы: " << sqmat.isSymmetric() << std::endl;

    //////////////////////////////////////////////////////////////////////
    std::cout << "Возведение матрицы в степень 3: " << std::endl << sqmat.pow(3);
    return 0;
}
