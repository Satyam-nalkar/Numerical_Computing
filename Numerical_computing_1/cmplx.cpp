#include "cmplx.hpp"

using namespace std;

// Constructor
cmplx::cmplx() {
    real = 0;
    img = 0;
    cout << "\n In cmplx default constructor .....\n";
}

void cmplx::display() {
    cout << real << " + " << img << "i" << endl;
}

cmplx cmplx::add(cmplx y) {
    cmplx c;
    c.real = this->real + y.real;
    c.img = this->img + y.img;
    c.display();
    return c;
}

cmplx cmplx::subtract(cmplx m) {
    cmplx c; 
    c.real = this->real - m.real;
    c.img = this->img - m.img;
    cout << "Result: ";
    c.display();
    return c;
}
