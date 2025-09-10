// A simple calculator

#include "Arithmetic.h"
#include "Calculator.h"
#include "ErrorHandling.h"
#include <iostream>
#include <string>
#include <string_view>

namespace AboutProgram {
const std::string version { "0.1.0" };

void print()
{
    std::cout
        << "A simple calculator\n"
        << "Version: " << version << '\n'
        << "By Itoshikey\n\n";
}
} // namespace AboutProgram

double getValue(std::string_view sv)
{
    while (true) {
        double value {};
        std::cout << sv;
        std::cin >> value;

        if (ErrorHandling::clearFailedExtraction()) {
            std::cout << "Error: Invalid input. Please try again\n";
            continue;
        }

        ErrorHandling::ignoreLine();
        return value;
    }
}

char getOperator()
{
    while (true) {
        char op {};
        std::cout << "Enter an operation (+, -, *, /, or %): ";
        std::cin >> op;

        if (!ErrorHandling::clearFailedExtraction())
            ErrorHandling::ignoreLine();

        switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return op;
        default:
            std::cerr << "That was an invalid input. Try again.\n";
        }
    }
}



void printResult(Calculator& c)
{
    auto fcn { ArithmetcFunctions::getArithmeticFunction(c.getOp()) };

    std::cout 
            << c.getX() << ' ' << c.getOp() << ' ' << c.getY() 
            << " = " << fcn(c.getX(), c.getY()) << '\n';
}

int main()
{
    AboutProgram::print();

    Calculator calculation {
        getValue("Enter a number: "),
        getOperator(),
        getValue("Enter another number: ")
    };

    while ((calculation.getOp() == '/') && (calculation.getY() == 0.0)) {
        std::cout << "The denominator cannot be zero. Try again.\n";
        calculation.setY(getValue("Enter another number: "));
    }

    printResult(calculation);

    return 0;
}