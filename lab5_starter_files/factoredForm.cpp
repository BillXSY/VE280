//
// Created by Zhuoer Zhu on 10/06/2020.
// Updated by Yanjun Chen on 16/06/2021.
//

#include "factoredForm.h"

// TODO: implement this constructor
QuadraticFunction::QuadraticFunction(float a_in, float b_in, float c_in) {
    a = a_in;
    float delta = b_in * b_in - 4 * a * c_in;
    if (delta == 0) {
        r1.real = -b_in / a / 2;
        r2.real = -b_in / a / 2;
        r1.imaginary = 0;
        r2.imaginary = 0;
    } else if (delta > 0) {
        r1.real = a < 0 ? (-b_in + sqrt(delta)) / a / 2 : (-b_in - sqrt(delta)) / a / 2;
        r2.real = a < 0 ? (-b_in - sqrt(delta)) / a / 2 : (-b_in + sqrt(delta)) / a / 2;
        r1.imaginary = 0;
        r2.imaginary = 0;
    } else {
        r1.real = -b_in / a / 2;
        r2.real = -b_in / a / 2;
        r1.imaginary = a < 0 ? (sqrt(-delta) / a / 2) : (-sqrt(-delta) / a / 2);
        r2.imaginary = a < 0 ? (-sqrt(-delta) / a / 2 ): (sqrt(-delta) / a / 2);
    }
}

float QuadraticFunction::getA() const {
    return a;
}

float QuadraticFunction::getB() const {
    // TODO: implement this function
    return -(r1.real + r2.real) * a;
}

float QuadraticFunction::getC() const {
    // TODO: implement this function
    return a * (r1.real * r2.real - r1.imaginary * r2.imaginary);
}

float QuadraticFunction::evaluate(float x) {
    // TODO: implement this function
    return a * x * x + getB() * x + getC();
}

Root QuadraticFunction::getRoot() {
    // TODO: implement this function
    Root rslt;
    rslt.realRootNum = (r1.imaginary == 0) + (r1.real != r2.real);
    rslt.roots[0] = r1;
    rslt.roots[1] = r2;
    return rslt;

}

bool QuadraticFunction::intersect(QuadraticFunction q) {
    // TODO: implement this function
    float b = getB();
    float c = getC();
    float d = q.getA();
    float e = q.getB();
    float f = q.getC();
    QuadraticFunction h(a-d, b-e, c-f);
    Root roots_h = h.getRoot();
    if ( roots_h.realRootNum > 0 ){
        return 1;
    }
    else return 0;
}