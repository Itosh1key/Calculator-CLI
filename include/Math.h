#ifndef MATH_H
#define MATH_H

#include <cmath>  // for std::pow(), std::sqrt()
#include <memory> // for std::unique_ptr, std::make_unique

class Math {
public:
    virtual ~Math() = default;

    Math(double x = 0.0, char op = ' ', double y = 0.0);

    void setX(double x);
    void setOp(char op);
    void setY(double y);

    double getX() const;
    char getOp() const;
    double getY() const;

    virtual void printResult() = 0;

protected:
    std::unique_ptr<double> m_x {};
    std::unique_ptr<char> m_op {};
    std::unique_ptr<double> m_y {};
};

#endif