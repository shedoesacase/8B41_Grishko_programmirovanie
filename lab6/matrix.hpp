#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>

class Matrix {
    protected:
        size_t rows; //строки
        size_t cols; //ряды
        std::vector<std::vector <int>> matrix; // Двумерный вектор для хранения элементов матрицы
    
    public:
        Matrix(); //Дефолтный конструктор
        Matrix(size_t r, size_t c);//Недефолтный конструктор
        ~Matrix(); //деструктор
        Matrix operator+(const Matrix &second);//оператор сложения
        Matrix operator-(const Matrix &second);//Оператор вычитания
        Matrix operator*(const int& num);//оператор умножения на число
        Matrix operator*(const Matrix &second);//оператор умножения на матрицу
        Matrix operator=(const Matrix &second);//оператор умножения на матрицу
        bool operator==(const Matrix &second);//оператор умножения на матрицу
        int max(); //поиск максимума
        
        
        /*переопределение оператора <<
        friend делает оператор дружественным. Т.е. если << является внешней функцией, она должна иметь доступ к приватным полям класса
        std::ostream& - возвращаемый тип операторной функции, т.е. оператор << возвращает ссылку на поток (os)
        std::ostream& os - параметр, представляющий поток вывода
        const Matrix& matrix - параметр, представляющий объект вывода
    
        Для оператора >> смысл схожий
        */
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    };
#endif