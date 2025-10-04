#include "BasicArithmetic.h"

BasicArithmetic::BasicArithmetic(double x, char op, double y)
    : Math { x, op, y }
{
}

// This function adds two numbers together.
constexpr double BasicArithmetic::add(double x, double y)
{
    return x + y;
}

// This function subtracts one number from another.
constexpr double BasicArithmetic::subtract(double x, double y)
{
    return x - y;
}

// This function multiplies two numbers together.
constexpr double BasicArithmetic::multiply(double x, double y)
{
    return x * y;
}

// This function performs a division on two numbers.
constexpr double BasicArithmetic::divide(double x, double y)
{
    if (y == 0.0)
        throw std::runtime_error { "Division by 0" };

    return x / y;
}

// This function returns the remainder of a division.
constexpr std::int64_t BasicArithmetic::modulo(double x, double y)
{
    if (y == 0.0)
        throw std::runtime_error { "Division by 0" };

    return static_cast<std::int64_t>(x) % 
           static_cast<std::int64_t>(y);
}

using BasicArithmeticFunction = std::function<double(double, double)>;
// This function returns a function pointer to the corresponding arithmetic function.
BasicArithmeticFunction BasicArithmetic::getBasicArithmeticFunction(char op) const
{
    switch (op) {
    case '+':
        return &add;
    case '-':
        return &subtract;
    case '*':
        return &multiply;
    case '/':
        return &divide;
    case '%':
        return &modulo;
    }

    return nullptr;
}

// This function prints the result of an operation performed on two numbers.
void BasicArithmetic::printResult()
{
    auto fcn { getBasicArithmeticFunction(getOp()) };

    try {
        std::cout << '\n';
        std::cout << getX() << ' ' << getOp() << ' ' << getY()
                  << " = " << fcn(getX(), getY()) << '\n';
    } 
    catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    } 
    catch (...) {}
}
