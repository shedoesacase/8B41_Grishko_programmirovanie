#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "matrix.hpp"

class SquareMatrix : public Matrix{
    public:
        SquareMatrix(size_t size);
        int determinant() const;
        bool isSymmetric();
        SquareMatrix pow(int n) const;
        SquareMatrix operator*(const SquareMatrix &second);
};

#endif