#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "ErrorHandling.h"
#include <iostream>
#include <string_view>

namespace UserInput {
    // This function prompts the user to 
    // enter a number, and then returns the input.
    constexpr double getValue(std::string_view sv)
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

    // This function prompts the user to enter
    // an operation, and then returns the input.
    constexpr char getOperator()
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
                std::cout << "Error: Invalid input. Please try again\n";
            }
        }
    }

    // The function will prompt the user to indicate 
    // whether they would like to perform additional calculations.
    constexpr bool finishedCalculations()
    { 
        while (true) {
            char ch {};
            std::cout << "\nDo you wish to perform another calculation? (y/n): ";
            std::cin >> ch;

            if (ErrorHandling::clearFailedExtraction())
                ErrorHandling::ignoreLine();

            switch (ch) {
            case 'Y':
            case 'y':
                return false; 
            case 'N':
            case 'n':
                return true;
            default:
                continue;
            }
        }
    }

    // This function prompts the user to select an option from the list.
    // And then returns the selection as an integer.
    constexpr int getSelection(const auto& options)
    {
        int choice {};

        do {
            std::cout << "\nWhat would you like to do?\n";
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
} // namespace UserInput
#endif