#include <iostream>
#include "cmplx.hpp"

using namespace std;

int main() {
    // Create objects
    cmplx a, b, result, sub;
    
    // Initialize objects
    a.real = 12;
    a.img = 4;
    b.real = 8;
    b.img = 6;
    
    // Display the initial values
    cout << "Complex 1: ";
    a.display();
    cout << "Complex 2: ";
    b.display();
    
    // Add the two objects
    result = a.add(b);
    sub = a.subtract(b);
    
    // Display the results
    cout << "Addition Result: ";
    result.display();
    
    cout << "Subtraction Result: ";
    sub.display();

    return 0;
}
