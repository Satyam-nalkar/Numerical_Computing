#include<iostream>
#include <cmath>
#include "new.hpp"
using namespace std;
int main() {
    double x0, tol;
    int Iterations;


    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> Iterations;

    double root = newtonRaphson(x0, tol, Iterations);

    if (!isnan(root)) {
        cout << "Root of the equation: " << root << endl;
    }

    return 0;
}
