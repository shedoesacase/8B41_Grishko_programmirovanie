#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <random>
#include "matrix.hpp"


//реализация деструктора
Matrix::~Matrix() {
    // Освобождение памяти не требуется, так как используется std::vector
}

//Реализация дефолтного конструктора 2 на 2 с нулями
Matrix::Matrix(): rows(2), cols(2) { 
    matrix.resize(rows); //Делаем размер вектора равным количеству строк, по сути устанавливаем количество строк в матрице
    for(size_t i = 0; i < rows; ++i){ //цикл заполнения строк
        matrix[i].resize(cols, 0); //В i-той строке матрицы будет cols элементов, равных 0
        }
    }

//реализация конструктора с заданными значениями
Matrix::Matrix(size_t r, size_t c): rows(r), cols(c) {
    matrix.resize(rows); // Устанавливаем количество строк
    for (size_t i = 0; i < rows; ++i) { // Цикл по строкам
        matrix[i].resize(cols); // Устанавливаем количество столбцов
        for (size_t j = 0; j < cols; ++j) { // Цикл по столбцам
            matrix[i][j] = std::rand() % 100; // Генерируем случайное число для каждой ячейки
        }
    }
}

//реализация оператора сложения
Matrix Matrix::operator+(const Matrix &second){
    if (rows != second.rows || cols != second.cols) //Складывать можно только матрицы с одинаковыми размерами
    {
        throw std::runtime_error("Сложить матрицы невозможно: размеры матриц не совпадают"); //исключение на случай, если матрица будет с другим размером
}
    Matrix res(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            res.matrix[i][j] = matrix[i][j] + second.matrix[i][j];
        }
    }
    return res;
}

//реализация оператора вычитания
Matrix Matrix::operator-(const Matrix &second){
    if (rows != second.rows || cols != second.cols) //Складывать можно только матрицы с одинаковыми размерами
    {
        throw std::runtime_error("вычесть матрицы невозможно: размеры матриц не совпадают"); //исключение на случай, если матрица будет с другим размером
}
    Matrix res(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            res.matrix[i][j] = matrix[i][j] - second.matrix[i][j];
        }
    }
    return res;
}

//реализация оператора умножения на число
Matrix Matrix::operator*(const int& num){
    Matrix res(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            res.matrix[i][j] = matrix[i][j] * num;
        }
    }
    return res;
}

//оператор умножения матрицы на матрицу
Matrix Matrix::operator*(const Matrix &second){ 
    if(cols != second.rows){ //количество столбцов первой матрицы должно совпадать с количеством строк второй матрицы
        throw std::runtime_error("Количество столбцов первой матрицы не совпадает с количеством строк второй матрицы");
    }
    Matrix res(rows, second.cols);
    for (size_t i = 0; i < rows; i++){ //проходит по всем строкам первой матрицы
        for (size_t j = 0; j < second.cols; j++){ //Проходит по всем столбцам второй матрицы
            res.matrix[i][j] = 0;
            for (size_t k = 0; k < cols; k++){ //умножаем складываем
                res.matrix[i][j] += matrix[i][k] * second.matrix[k][j];
            }
        }
    }
    return res;
}

//реализация оператора присваивания
Matrix Matrix::operator=(const Matrix &second){
    if (this == &second){
        return *this; //Если матрицы итак равны, мы возвращаем исходную
    }
    
    rows = second.rows; //копируем размеры
    cols = second.cols;
    matrix = second.matrix; //копируем данные
    return *this;
}

//реализация оператора сравнения
bool Matrix::operator==(const Matrix &second){
    if(rows != second.rows || cols != second.cols){
        return false; //размеры не равны, значит false
    }
    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            if(matrix[i][j] != second.matrix[i][j]) return false; //Если хотя бы один элемент в матрицах не равен, вернется false
        }
    }
    return true;
}

//реализация оператора ввода
std::istream& operator>>(std::istream& is, Matrix& matrix){
    for(size_t i = 0; i < matrix.rows; ++i){
        for(int j = 0; j < matrix.cols; ++j){
            is >> matrix.matrix[i][j];
        }
    }
    return is;
}

//реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    for(size_t i = 0; i < matrix.rows; ++i){ // Проходим по строкам
        for(size_t j = 0; j < matrix.cols; ++j){ // Проходим по столбцам
            os << matrix.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os; // Возвращаем поток для поддержки цепочки операций
}

//поиск максимума
int Matrix::max()
{
    int max = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}