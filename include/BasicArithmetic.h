#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "Math.h"
#include <exception>  // for std::exception
#include <functional> // for std::function
#include <iostream>
#include <stdexcept>  // for std::runtime_error

// Basic arithmetic functions
struct BasicArithmetic : public Math {
    explicit BasicArithmetic(double x, char op, double y);

    static constexpr double add(double x, double y);
    static constexpr double subtract(double x, double y);
    static constexpr double multiply(double x, double y);
    static constexpr double divide(double x, double y);
    static constexpr int modulo(double x, double y);

    using BasicArithmeticFunction = std::function<double(double, double)>;
    BasicArithmeticFunction getBasicArithmeticFunction(char op) const;

    void printResult() override;
};

#endif