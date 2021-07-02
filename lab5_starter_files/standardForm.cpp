//
// Created by Zhuoer Zhu on 10/06/2020.
// Updated by Yanjun Chen on 16/06/2021.
//

#include <cmath>
#include "standardForm.h"

QuadraticFunction::QuadraticFunction(float a_in, float b_in, float c_in) {
    // TODO: implement this constructor
    a = a_in;
    b = b_in;
    c = c_in;
}

float QuadraticFunction::getA() const {
    return a;
}

float QuadraticFunction::getB() const {
    return b;
}

float QuadraticFunction::getC() const {
    return c;
}

float QuadraticFunction::evaluate(float x) {
    // TODO: implement this function
    return a * x * x + b * x + c;
}

Root QuadraticFunction::getRoot() {
    // TODO: implement this function
    Root rslt;
    float delta = b * b - 4 * a * c;
    if (delta == 0) {
        rslt.realRootNum = 1;
        rslt.roots[0].real = -b / a / 2;
        rslt.roots[1].real = -b / a / 2;
        rslt.roots[0].imaginary = 0;
        rslt.roots[1].imaginary = 0;
    } else if (delta > 0) {
        rslt.realRootNum = 2;
        rslt.roots[0].real = a < 0 ? (-b + sqrt(delta)) / a / 2 : (-b - sqrt(delta)) / a / 2;
        rslt.roots[1].real = a < 0 ? (-b - sqrt(delta)) / a / 2 : (-b + sqrt(delta)) / a / 2;
        rslt.roots[0].imaginary = 0;
        rslt.roots[1].imaginary = 0;
    } else {
        rslt.realRootNum = 0;
        rslt.roots[0].real = -b / a / 2;
        rslt.roots[1].real = -b / a / 2;
        rslt.roots[0].imaginary = a < 0 ? (sqrt(-delta) / a / 2) : (-sqrt(-delta) / a / 2);
        rslt.roots[1].imaginary = a < 0 ? (-sqrt(-delta) / a / 2 ): (sqrt(-delta) / a / 2);
    }
    return rslt;
}

bool QuadraticFunction::intersect(QuadraticFunction q) {
    // TODO: implement this function
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