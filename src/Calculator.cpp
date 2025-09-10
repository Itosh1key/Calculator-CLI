#include "Calculator.h"

// Normal constructor definition
Calculator::Calculator(double x, char op, double y)
    : m_x { std::make_unique<double>(x) }
    , m_op { std::make_unique<char>(op) }
    , m_y { std::make_unique<double>(y) }
{
}

// Setters
void Calculator::setX(double x) const
{
    if (m_x == nullptr)
        return;

    *m_x = x;
}
void Calculator::setOp(char op) const
{
    if (m_op == nullptr)
        return;

    *m_op = op;
}
void Calculator::setY(double y) const
{
    if (m_y == nullptr)
        return;
        
    *m_y = y;
}

// Getters
double Calculator::getX() const
{
    if (m_x == nullptr)
        return 0.0;

    return *m_x;
}

char Calculator::getOp() const
{
    if (m_op == nullptr)
        return ' ';

    return *m_op;
}

double Calculator::getY() const
{
    if (m_y == nullptr)
        return 0.0;

    return *m_y;
}