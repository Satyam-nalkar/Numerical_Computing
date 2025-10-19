#include <iostream>
#include <cmath>
using namespace std;


double function(double x) {
    return x*x*x - 2*x - 5;   //  f(x) = x^3 - x^2 + 2
}


double bisection(double a, double b, double tol) {
    if (function(a) * function(b) >= 0) {
        cout << "a and b must have opposite signs." << endl;
        return NAN;
    }

    
    double c;
    while ((b - a) >= tol) {
    
        c = (a + b) / 2;
       
        if (function(c) * function(a) < 0)
             b = c;
         else
             a = c;
    }
    return c;
}


int main() {
    double a, b, tol;
    
    cout << "Enter the initial interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance: ";
    cin >> tol;
    
    double root = bisection(a, b, tol);
    
    if (!isnan(root)) {
        cout << "The root of the equation is: " << root << endl;
    }
    
    return 0;
}
