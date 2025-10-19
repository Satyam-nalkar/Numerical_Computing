#include <iostream>
#include <cmath>

using namespace std;

double g(double x) {
    return cbrt((2*x + 5) / 2);
}

// Fixed Point Iteration Method Function
double fixedPointIteration(double x0, double tol, int maxIterations) {
    double x = x0;
    
    for (int i = 1; i <= maxIterations; i++) {
        double x1 = g(x); 

        cout << "Iteration " << i << ": x = " << x1 << endl;

        if (fabs(x1 - x) < tol) {
            return x1;
        }

        x = x1;
    }

    cout << "Max iterations reached. Approximate root: ";
    return x;
}

int main() {
    double x0, tol;
    int maxIterations;

    // Taking input
    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIterations;

    double root = fixedPointIteration(x0, tol, maxIterations);

    cout << "Root of the equation: " << root << endl;

    return 0;
}
