#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    ~Matrix();

    void inputFromFile(const string& filename);
    void display() const;

    Matrix add(const Matrix& second) const;
    Matrix sub(const Matrix& second) const;
    Matrix mult(const Matrix& second) const;

    void gaussianElimination(Matrix& B);
    void backSubstitution(Matrix& B, double X[]);

    void luDecomposition(Matrix& L, Matrix& U);
    void multiplyLU(const Matrix& L, const Matrix& U, Matrix& resultLU);

    bool isIdentity() const;
    bool isSymmetric() const;
    bool isDiagonallyDominant();
    bool makeDiagonallyDominant(Matrix &B);
    int gaussSeidel(Matrix &B, double* X, double tolerance);
    int gaussJacobi(Matrix &B, double* X, double tolerance);
    double lagrangeInterpolationFromFile(const string& filename);
    double lagrangeInterpolation(double x[], double y[], int n, double xp);
    int getRows() const { return rows; }  
    int getCols() const { return cols; }  
};

