// main.cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include "newton_raphson.h"

using namespace std;

int main() {
    double x0, tol;
    int maxIterations;

    ifstream inputFile("input.txt");

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    inputFile >> x0 >> tol >> maxIterations;

    if (!inputFile) {
        cerr << "Invalid or incomplete input data!" << endl;
        return 1;
    }

    inputFile.close();

    double root = newtonRaphson(x0, tol, maxIterations);

    if (!isnan(root)) {
        cout << "Root of the equation: " << root << endl;
    }

    return 0;
}
