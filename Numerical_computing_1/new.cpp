#include <iostream>
#include <cmath>
#include "new.hpp"
using namespace std;

double function(double x) {
    return  x*x*x*x + 0*x*x*x - 14*x*x + 45; 
}

double derivative(double x) {
    return 4*x*x*x - 28*x;           
}


double newtonRaphson(double x0, double tol, int Iterations) {
    double x = x0;
    
    for (int i = 1; i <= Iterations; i++) {
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


