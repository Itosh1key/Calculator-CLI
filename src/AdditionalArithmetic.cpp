#include "AdditionalArithmetic.h"

AdditionalArithmetic::AdditionalArithmetic(double x)
    : Math { x, ' ', 0.0 }
{
}

// This function prompts the user to enter an exponent and then returns it.
double AdditionalArithmetic::getExponent() const
{
    while (true) {
        double exponent {};
        std::cout << "\nEnter an exponent: ";
        std::cin >> exponent;

        if (ErrorHandling::clearFailedExtraction())
            continue;

        ErrorHandling::ignoreLine();

        return exponent;
    }
}

// This function calculates the exponentiation of a base and an exponent.
double AdditionalArithmetic::exponentiation(double base, double exponent) const
{   
    return std::pow(base, exponent);
}

// This function calculates the square root of a number.
double AdditionalArithmetic::squareRoot(double x) const
{
    return std::sqrt(x);
}

// This function calculates the digit sum of a number.
std::int64_t AdditionalArithmetic::digitSum(std::int64_t n) const
{
    std::int64_t digitSum {};

    while (n > 0) {
        digitSum += n % 10;
        n /= 10;
    }

    return digitSum;
}

// This function calculates the digital root of a number.
std::int64_t AdditionalArithmetic::digitalRoot(std::int64_t n) const
{
    return (n - 1) % 9 + 1;
}

// This function prompts the user to select an operation from the list.
// And then returns the selection as an integer.
int AdditionalArithmetic::getSelection(const auto& options) const
{
    int choice {};

    do {
        std::cout << "\nSelect an additonal Arithmetic operation:\n";
        for (std::size_t index { 0 }; index < options.size(); ++index)
            std::cout << (index + 1) << ") " << options[index] << '\n';

        std::cout << '>';
        std::cin >> choice;

        if (ErrorHandling::clearFailedExtraction())
            continue;

        ErrorHandling::ignoreLine();

    } while (choice < 1 || static_cast<std::size_t>(choice) > options.size());

    return choice;
}

// Helper member function
int AdditionalArithmetic::selectOperation() const
{
    using namespace std::string_view_literals;
    constexpr std::array options { // Subject to change
        "Exponentiation (POW)"sv,
        "Square Root (SQRT)"sv,
        "Digit Sum (DS)"sv,
        "Digital Root (DR)"sv,
        "Back"sv
    };

    int selection { getSelection(options) };

    return selection;
}

// This function prints the result of the exponentiation operation.
void AdditionalArithmetic::printExponentiation()
{
    double exponent { getExponent() };

    std::cout << '\n';
    std::cout << getX() << '^' << exponent << " = "
              << exponentiation(getX(), exponent) << '\n';
}

// This function prints the result of the square root operation.
void AdditionalArithmetic::printSquareRoot()
{
    std::cout << "\nSQRT(" << getX() << ") = " << squareRoot(getX()) << '\n';
}

// This function prints the result of the digit sum operation.
void AdditionalArithmetic::printDigitSum()
{
    std::int64_t n { static_cast<std::int64_t>(getX()) };

    std::cout << "\nDS(" << n << ") = " << digitSum(n) << '\n';
}

// This function prints the result of the digital root operation.
void AdditionalArithmetic::printDigitalRoot()
{
    std::int64_t n { static_cast<std::int64_t>(getX()) };

    std::cout << "\nDR(" << n << ") = " << digitalRoot(n) << '\n';
}

// Helper memeber function
void AdditionalArithmetic::printResult()
{
    switch (selectOperation()) {
    case 1:
        printExponentiation();
        break;
    case 2:
        printSquareRoot();
        break;
    case 3:
        printDigitSum();
        break;
    case 4:
        printDigitalRoot();
        break;
    case 5:
        // Back
        break;
    }
}