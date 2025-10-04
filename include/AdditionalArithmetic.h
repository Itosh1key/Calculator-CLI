#ifndef ADDITIONAL_ARITHMETIC_H
#define ADDITIONAL_ARITHMETIC_H

#include "ErrorHandling.h"
#include "Math.h"
#include <cstdint> // for fixed_sized integers
#include <iostream>

class AdditionalArithmetic : public Math {
public:
    explicit AdditionalArithmetic(double x);

    double getExponent() const;
    double exponentiation(double base, double exponent) const;
    double squareRoot(double x) const;

    std::int64_t digitSum(std::int64_t x) const; 
    std::int64_t digitalRoot(std::int64_t x) const;

    int getSelection(const auto& options) const;
    int selectOperation() const;

    void printExponentiation();
    void printSquareRoot();
    void printDigitSum();
    void printDigitalRoot();

    void printResult() override;
};

#endif