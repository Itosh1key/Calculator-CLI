// Arithmetic functions

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <functional>

namespace ArithmetcFunctions {
    double add(double x, double y);
    double substract(double x, double y);
    double multiply(double x, double y);
    double divide(double x, double y);
    int modulo(double x, double y);

    using ArithmeticFunction = std::function<double(double, double)>;

    ArithmeticFunction getArithmeticFunction(char op);
} // namespace ArithmetcFunctions

#endif