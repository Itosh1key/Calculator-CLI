#include "Arithmetic.h"

namespace ArithmetcFunctions {
    double add(double x, double y)
    {
        return x + y;
    }

    double substract(double x, double y)
    {
        return x - y;
    }

    double multiply(double x, double y)
    {
        return x * y;
    }

    double divide(double x, double y)
    {
        return x / y;
    }

    int modulo(double x, double y)
    {
        return static_cast<int>(x) % static_cast<int>(y);
    }

    using ArithmeticFunction = std::function<double(double, double)>;

    ArithmeticFunction getArithmeticFunction(char op)
    {
        switch (op) {
        case '+': return &add;
        case '-': return &substract;
        case '*': return &multiply;
        case '/': return &divide;
        case '%': return &modulo;
        }

        return nullptr;
    }
} // namespace ArithmetcFunctions