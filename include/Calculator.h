#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>

class Calculator {
public: // The public interface of the class
    // Default constructor declaration
    explicit Calculator(double x, char op, double y);

    // Copy constructor (deleted)
    Calculator(const Calculator& calculator) = delete;

    // Trivial member functions
    // Setters
    void setX(double x) const;
    void setOp(char op) const;
    void setY(double y) const;

    // Getters
    double getX() const;
    char getOp() const;
    double getY() const;

private: // The implementation of the class
    std::unique_ptr<double> m_x {};
    std::unique_ptr<char> m_op {};
    std::unique_ptr<double> m_y {};
};

#endif