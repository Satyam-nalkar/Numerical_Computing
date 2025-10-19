#include <iostream>
#include <string>
#include "Matrix.hpp"
using namespace std;
int main() {
    string filename;

    // Matrix Addition, Subtraction, and Multiplication
    Matrix matrix1(0, 0), matrix2(0, 0);
    
    cout << "Enter filename for Matrix 1: ";
    cin >> filename;
    matrix1.inputFromFile(filename);
    
    cout << "Enter filename for Matrix 2: ";
    cin >> filename;
    matrix2.inputFromFile(filename);

    if (matrix1.getRows() != matrix2.getRows() || matrix1.getCols() != matrix2.getCols()) {
        cout << "Error: Matrices must have the same dimensions for addition and subtraction!\n";
        return 1;
    }
    
    Matrix result = matrix1.add(matrix2);
    cout << "Summation of Matrix:\n";
    result.display();
    
    Matrix result2 = matrix1.sub(matrix2);
    cout << "Subtraction of Matrix:\n";
    result2.display();
    
    if (matrix1.getCols() != matrix2.getRows()) {
        cout << "Error: Matrices cannot be multiplied (incompatible dimensions)!\n";
    } else {
        Matrix result3 = matrix1.mult(matrix2);
        cout << "Multiplication of Matrix:\n";
        result3.display();
    }

    // Identity and Symmetric Check
    if (matrix1.isIdentity()) {
        cout << "Matrix 1 is an identity matrix.\n";
    } else {
        cout << "Matrix 1 is not an identity matrix.\n";
    }

    if (matrix1.isSymmetric()) {
        cout << "Matrix 1 is symmetric.\n";
    } else {
        cout << "Matrix 1 is not symmetric.\n";
    }

    // Gaussian Elimination
    Matrix A(0, 0), B(0, 1);
    
    cout << "Enter filename for Left Matrix (A): ";
    cin >> filename;
    A.inputFromFile(filename);
    
    cout << "Enter filename for Right Matrix (B): ";
    cin >> filename;
    B.inputFromFile(filename);

    if (A.getRows() != B.getRows()) {
        cout << "Error: A and B must have the same number of rows for Gaussian Elimination!\n";
        return 1;
    }

    A.gaussianElimination(B);

    double* solution = new double[A.getRows()];
    A.backSubstitution(B, solution);
    
    cout << "Values for x:\n";
    for (int i = 0; i < A.getRows(); i++) {
        cout << "x[" << i << "] = " << solution[i] << endl;
    }
    delete[] solution;

    // LU Decomposition
    cout << "Enter filename for LU Decomposition matrix: ";
    cin >> filename;
    matrix1.inputFromFile(filename);
    
    if (matrix1.getRows() != matrix1.getCols()) {
        cout << "Error: LU Decomposition only works for square matrices!\n";
        return 1;
    }

    Matrix L(matrix1.getRows(), matrix1.getCols()), U(matrix1.getRows(), matrix1.getCols());
    matrix1.luDecomposition(L, U);
    
    cout << "Lower Triangular Matrix (L):\n";
    L.display();
    cout << "Upper Triangular Matrix (U):\n";
    U.display();

    Matrix resultLU(matrix1.getRows(), matrix1.getCols());
    matrix1.multiplyLU(L, U, resultLU);
    
    cout << "Matrix obtained by multiplying L and U:\n";
    resultLU.display();
    


    //Gauss-Seidel and gauss-Jacobi Matrix 

    cout << "Enter filename for Gauss-Seidel matrix A: ";
    cin >> filename;
    A.inputFromFile(filename);
    
    cout << "Enter filename for Gauss-Seidel right-hand side B: ";
    cin >> filename;
    B.inputFromFile(filename);
    
    if (A.getRows() != A.getCols()) {
        cout << "Error: Gauss-Seidel requires a square matrix!\n";
        return 1;
    }
    
    if (A.getRows() != B.getRows()) {
        cout << "Error: A and B must have the same number of rows!\n";
        return 1;
    }
    
    if (!A.isDiagonallyDominant()) {
        if (A.makeDiagonallyDominant(B)) {
            cout << "Matrix made diagonally dominant by row swaps.\n";
        } else {
            cout << "Failed to make matrix diagonally dominant.\n";
        }
    }

    double *X = new double[A.getRows()];
    // int maxIterations;
    double tolerance;
    
    // cout << "Enter maximum iterations for Gauss-Seidel: ";
    // cin >> maxIterations;
    
    cout << "Enter tolerance value for Gauss-Seidel: ";
    cin >> tolerance;
    
    A.gaussSeidel(B, X,  tolerance);


    cout <<"\n";
    cout << "Gauss Jacobi \n";
    A.gaussJacobi(B, X, tolerance);




//Lagranges Interpolation     

cout << "Enter the input file name: ";
cin >> filename;

Matrix m;  
m.lagrangeInterpolationFromFile(filename); 

    return 0;
}
