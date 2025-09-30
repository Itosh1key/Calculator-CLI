#include "Math.h"

Math::Math(double x, char op, double y)
        : m_x { std::make_unique<double>(x) }
        , m_op { std::make_unique<char>(op) }
        , m_y { std::make_unique<double>(y) }
    {
    }

void Math::setX(double x)
{
    if (m_x == nullptr)
        *m_x = 0.0;

    *m_x = x;
}

void Math::setOp(char op)
{
    if (m_op == nullptr)
        *m_op = ' ';

    *m_op = op;
}

void Math::setY(double y)
{
    if (m_y == nullptr)
        *m_y = 0.0;

    *m_y = y;
}

double Math::getX() const
{
    if (m_x == nullptr)
        return 0.0;

    return *m_x;
}

char Math::getOp() const
{
    if (m_op == nullptr)
        return ' ';

    return *m_op;
}

double Math::getY() const
{
    if (m_y == nullptr)
        return 0.0;

    return *m_y;
}