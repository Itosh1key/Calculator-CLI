// This calculator can perform basic arithmetic operations (+, -, *, /, and %) 
// as well as additional operations, including exponentiation (POW), square root
// extraction (SQRT), digit sum (DS), and digital root calculation (DR).

#include "AdditionalArithmetic.h"
#include "BasicArithmetic.h"
#include "ErrorHandling.h"
#include "UserInput.h"
#include <iostream>
#include <string>
#include <string_view>

// This namespace manages general program information.
namespace AboutProgram {
    constexpr std::string name { "Calculator" };
    constexpr std::string version { "1.0.0" };
    constexpr std::string author { "Itosh1key" };

    // This function prints the general information about the program.
    void print()
    {
        std::cout << name << " v" << version
                << "\nBy " << author << "\n";
    }
} // namespace AboutProgram

// Helper function.
constexpr int selectOption()
{
    using namespace std::string_view_literals;
    constexpr std::array options { // Subject to change
        "Basic Arithmetic (+, -, *, /, or %)"sv,
        "Additional Arithmetic (POW, SQRT, DS, or DR)"sv,
        "Quit"sv
    };

    int selection { UserInput::getSelection(options) };

    return selection;
}

// This function performs basic arithmetic operations, such as
// addition, subtraction, multiplication, division, and remainder (modulo).
void calculateBasicArithmetic()
{
    BasicArithmetic calculate {
        UserInput::getValue("\nEnter a number: "),
        UserInput::getOperator(),
        UserInput::getValue("Enter another number: ")
    };

    while ((calculate.getOp() == '/') && (calculate.getY() == 0.0)) {
        std::cout << "The denominator cannot be zero. Try again.\n";
        calculate.setY(UserInput::getValue("Enter another number: "));
    }

    calculate.printResult();
}

// This function performs additional arithmetic operations, including
// exponentiation, taking the square root, calculating the digit sum, and 
// finding the digital root.
void calculateAdditionalArithmetic()
{
    AdditionalArithmetic calculate { UserInput::getValue("\nEnter a number: ") };

    calculate.printResult();
}

int main()
{
    AboutProgram::print();

    // A flag that will be used to break out of the loop
    bool breakOut { false };

    /* We could have used a goto statement instead, but that goes
        against the best practices. We don't want to create spaghetti code. */

    do {
        switch (selectOption()) {
        case 1:
            calculateBasicArithmetic();
            break;
        case 2:
            calculateAdditionalArithmetic();
            break;
        case 3: // If the user has chosen the option "Quit"
            breakOut = true; // activate the flag
            break;
        }

        if (breakOut) // If the flag is active
            break; // break out of the loop

    } while (!UserInput::finishedCalculations());

    std::cout << "\nBye!\n";
}