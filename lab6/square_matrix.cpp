#include "square_matrix.hpp"


//Конструктор наследуется из основного класса
SquareMatrix::SquareMatrix(size_t size): Matrix(size, size) {}

//оператор умножения матрицы на матрицу
SquareMatrix SquareMatrix::operator*(const SquareMatrix &second){ 
    if(cols != second.rows){ //количество столбцов первой матрицы должно совпадать с количеством строк второй матрицы
        throw std::runtime_error("Количество столбцов первой матрицы не совпадает с количеством строк второй матрицы");
    }
    SquareMatrix res(rows);
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

int SquareMatrix::determinant() const {
    size_t n = rows; // Размер матрицы (количество строк или столбцов)

    // Базовый случай: определитель матрицы 1x1
    if (n == 1) {
        return matrix[0][0];
    }

    // Базовый случай: определитель матрицы 2x2
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0; // Определитель
    for (size_t col = 0; col < n; ++col) { // Цикл проходит по столбцам
        // Создание минора
        std::vector<std::vector<int>> minorData(n - 1, std::vector<int>(n - 1));
        for (size_t i = 1; i < n; ++i) { // Цикл заполняет минор
            size_t minorRow = 0;
            for (size_t j = 0; j < n; ++j) {
                if (j == col) continue; // Пропускаем текущий столбец
                minorData[minorRow][i - 1] = matrix[i][j]; // Записываем элементы в минор
                minorRow++;
            }
        }

        // Создаем временный объект SquareMatrix для минора
        SquareMatrix minor(n - 1);
        minor.matrix = minorData;

        // Рекурсивный вызов функции для текущего минора
        int next = matrix[0][col] * minor.determinant();
        det += (col % 2 == 0 ? 1 : -1) * next; // Знак зависит от чётности индекса
    }

    return det;
}

bool SquareMatrix::isSymmetric(){
    // Проверяем симметричность элементов
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = i + 1; j < cols; ++j) { // Проверяем только над главной диагональю
            if (matrix[i][j] != matrix[j][i]) {
                return false; // Несимметричная, если найдена несимметричная пара
            }
        }
    }

    return true;
}

// Метод для возведения матрицы в степень
SquareMatrix SquareMatrix::pow(int n) const {
    if (n < 0) {
        throw std::invalid_argument("Отрицательная степень не поддерживается");
    }

    // Создаем единичную матрицу
    SquareMatrix result(rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            result.matrix[i][j] = (i == j) ? 1 : 0; // Единичная матрица
        }
    }

    if (n == 0) {
        return result; // Возвращаем единичную матрицу
    }

SquareMatrix current = *this; // Текущая матрица
for (int i = 0; i < n; ++i) {
    result = result * current; // Умножаем результат на текущую матрицу
}

return result;
}
