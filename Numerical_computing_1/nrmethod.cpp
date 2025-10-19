// newton_raphson.cpp
#include <iostream>
#include <cmath>
#include "nrmethod.hpp"

using namespace std;

double function(double x) {
    return x * x * x - 2 * x - 5;
}

double derivative(double x) {
    return 3 * x * x - 2;
}

double newtonRaphson(double x0, double tol, int maxIterations) {
    double x = x0;

    for (int i = 1; i <= maxIterations; i++) {
        double fx = function(x);
        double dfx = derivative(x);

        if (dfx == 0) {
            cout << "Derivative is zero. No solution found!" << endl;
            return NAN;
        }

        double x1 = x - (fx / dfx);

        cout << "Iteration " << i << ": x = " << x1 << ", f(x) = " << fx << endl;

        if (fabs(x1 - x) < tol) {
            return x1;
        }

        x = x1;
    }

    cout << "Max iterations reached. Approximate root: ";
    return x;
}
