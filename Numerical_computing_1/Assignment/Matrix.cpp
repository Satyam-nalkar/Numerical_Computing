#include "Matrix.hpp"
#include <fstream>
#include <iostream>
using namespace std;
void Matrix::inputFromFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    int newRows, newCols;
    file >> newRows >> newCols;

    if (data && (newRows != rows || newCols != cols)) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }

    rows = newRows;
    cols = newCols;

    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> data[i][j])) {
                cout << "Error: Invalid data format in file.\n";
                return;
            }
        }
    }

    file.close();
}

//  Constructor

Matrix::Matrix() {
    rows = 0;
    cols = 0;
    data = nullptr;
}



Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
    }
}

//  Copy Constructor



Matrix::Matrix(const Matrix &other) {
    rows = other.rows;
    cols = other.cols;
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

//  Destructor
Matrix::~Matrix() {
    if (data) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

//  Display Matrix
void Matrix::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

//  Matrix Addition
Matrix Matrix::add(const Matrix& second) const {
    if (rows != second.rows || cols != second.cols) {
        cout << "Error: Matrices must have the same dimensions for addition!\n";
        return Matrix(0, 0);
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + second.data[i][j];
        }
    }
    return result;
}

//  Matrix Subtraction 
Matrix Matrix::sub(const Matrix &second) const {
    if (rows != second.rows || cols != second.cols) {
        cout << "Error: Matrices must have the same dimensions for subtraction!\n";
        return Matrix(0, 0);
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - second.data[i][j];
        }
    }
    return result;
}

//  Matrix Multiplication 
Matrix Matrix::mult(const Matrix &second) const {
    if (cols != second.rows) {
        cout << "Error: Matrices cannot be multiplied (incompatible dimensions)!\n";
        return Matrix(0, 0);
    }

    Matrix result(rows, second.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < second.cols; j++) {
            result.data[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < second.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * second.data[k][j];
            }
        }
    }

    return result;
}

// Gaussian Elimination
void Matrix::gaussianElimination(Matrix& B) {
    for (int k = 0; k < rows; k++) {
        if (data[k][k] == 0) {
            for (int i = k + 1; i < rows; i++) {
                if (data[i][k] != 0) {
                    swap(data[k], data[i]);
                    swap(B.data[k], B.data[i]);
                    break;
                }
            }
        }

        for (int i = k + 1; i < rows; i++) {
            double factor = static_cast<double>(data[i][k]) / data[k][k];
            for (int j = k; j < cols; j++) {
                data[i][j] -= factor * data[k][j];
            }
            B.data[i][0] -= factor * B.data[k][0];
        }
    }
}

// Back Substitution
void Matrix::backSubstitution(Matrix& B, double X[]) {
    for (int i = rows - 1; i >= 0; i--) {
        if (data[i][i] == 0) {
            cout << "No unique solution exists.\n";
            return;
        }
        X[i] = B.data[i][0];
        for (int j = i + 1; j < cols; j++) {
            X[i] -= data[i][j] * X[j];
        }
        X[i] /= data[i][i];
    }
}



bool Matrix::isIdentity() const {
    if (rows != cols) return false; // Identity matrix must be square

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

//  Check if Matrix is Symmetric
bool Matrix::isSymmetric() const {
    if (rows != cols) return false; // Symmetric matrix must be square

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != data[j][i]) {
                return false;
            }
        }
    }
    return true;
}




void Matrix::luDecomposition(Matrix& L, Matrix& U) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < j)
                L.data[i][j] = 0;
            else {
                L.data[i][j] = data[i][j];
                for (int k = 0; k < j; k++) {
                    L.data[i][j] -= L.data[i][k] * U.data[k][j];
                }
            }
        }

        for (int j = 0; j < cols; j++) {
            if (j < i)
                U.data[i][j] = 0;
            else if (j == i)
                U.data[i][j] = 1;
            else {
                U.data[i][j] = data[i][j] / L.data[i][i];
                for (int k = 0; k < i; k++) {
                    U.data[i][j] -= (L.data[i][k] * U.data[k][j]) / L.data[i][i];
                }
            }
        }
    }
}



void Matrix::multiplyLU(const Matrix &L, const Matrix &U, Matrix &resultLU) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultLU.data[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                resultLU.data[i][j] += L.data[i][k] * U.data[k][j];
            }
        }
    }
}


bool Matrix::isDiagonallyDominant() {
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            if (i != j) {
                sum += abs(data[i][j]);
            }
        }
        if (abs(data[i][i]) < sum) {
            return false; 
        }
    }    
    return true;
}



bool Matrix::makeDiagonallyDominant(Matrix &B) {
    for (int i = 0; i < rows; i++) {
        double rowSum = 0;

        // Sum of non-diagonal elements
        for (int j = 0; j < cols; j++) {
            if (i != j) {
                rowSum += abs(data[i][j]);
            }
        }

        // Check if current diagonal element is already dominant
        if (abs(data[i][i]) < rowSum) {
            // Try to find a better row to swap
            int maxRow = i;
            double maxVal = abs(data[i][i]);

            for (int k = i + 1; k < rows; k++) {
                double diagVal = abs(data[k][i]);
                double sum = 0;

                for (int j = 0; j < cols; j++) {
                    if (j != i) sum += abs(data[k][j]);
                }

                // Check if the current row is a better candidate for swapping
                if (diagVal >= sum && diagVal > maxVal) {
                    maxVal = diagVal;
                    maxRow = k;
                }
            }

            
            if (maxRow != i) {
                swap(data[i], data[maxRow]);
                swap(B.data[i], B.data[maxRow]);
            } else {
                return false;  
            }
        }
    }

    return isDiagonallyDominant();
}





//Gauss Seidal
int Matrix::gaussSeidel(Matrix &B, double* X, double tolerance) {
    if (rows != cols) {
        cout << "Error: Gauss-Seidel requires a square matrix.\n";
        return -1;
    }

    if (!isDiagonallyDominant()) {
        cout << "Error: The matrix is not diagonally dominant. Gauss-Seidel may not converge.\n";
        return -1;
    }

    int n = rows;
    double *oldX = new double[n];
    for (int i = 0; i < n; i++)
        X[i] = 0;

    int iter = 0;
    while (true) {
        for (int i = 0; i < n; i++)
            oldX[i] = X[i];

        for (int i = 0; i < n; i++) {
            double sum = B.data[i][0];
            for (int j = 0; j < cols; j++) {
                if (j != i) {        
                    sum -= data[i][j] * X[j];
                }                    
            }
            X[i] = sum / data[i][i];
        }

        cout << "Iteration " << iter + 1 << ": ";
        for (int i = 0; i < n; i++) {
            cout << X[i] << " ";
        }
        cout << endl;

        double maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(X[i] - oldX[i]));
        }

        iter++;

        if (maxDiff < tolerance) {
            delete[] oldX;
            return iter;
        }
    }

    delete[] oldX;
    return -1;
}




// Gauss Jocobi
int Matrix::gaussJacobi(Matrix &B, double* X, double tolerance) {
    if (rows != cols) {
        cout << "Error: Gauss-Jacobi requires a square matrix.\n";
        return -1;
    }

    if (!isDiagonallyDominant()) {
        cout << "Error: The matrix is not diagonally dominant. Gauss-Jacobi may not converge.\n";
        return -1;
    }

    int n = rows;
    double* oldX = new double[n];


    for (int i = 0; i < n; i++) {
        X[i] = 0;
        oldX[i] = 0;
    }

    int iter = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            double sum = B.data[i][0];
            for (int j = 0; j < cols; j++) {
                if (j != i) {
                    sum -= data[i][j] * oldX[j];  
                }
            }
            X[i] = sum / data[i][i];
        }

        cout << "Iteration " << iter + 1 << ": ";
        for (int i = 0; i < n; i++) {
            cout << X[i] << " ";
        }
        cout << endl;

        double maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(X[i] - oldX[i]));
            oldX[i] = X[i]; 
        }

        iter++;

        if (maxDiff < tolerance) {
            delete[] oldX;
            return iter;
        }
    }

    delete[] oldX;
    return -1;
}




// Lagrange Interpolation


double Matrix::lagrangeInterpolationFromFile(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file!\n";
        return -1.0;
    }

    int n;
    infile >> n;

    double* x = new double[n];
    double* y = new double[n];

    for (int i = 0; i < n; i++) infile >> x[i];
    for (int i = 0; i < n; i++) infile >> y[i];

    double xp;
    infile >> xp;
    infile.close();

    double result6 = lagrangeInterpolation(x, y, n, xp);
    cout << "Interpolated value at x = " << result6 << endl;  // Print result



    delete[] x;
    delete[] y;

    return result6;
}


double Matrix::lagrangeInterpolation(double x[], double y[], int n, double xp) {
    double yp = 0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }  
        }
        yp += term;
    }

    return yp;
}