#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <cmath>
#include <string>
#include "figure.h"

class Square : public Figure {
public:
    Square();
    Square(double, double, double, double, double, double, double, double);
    ~Square() noexcept override;
    Square(const Square& other);
    Square(Square&& other) noexcept;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;

    pair<double, double> get_centr() const override;
    operator double() const override;
    bool eq(const Figure& other) const override;
    void read(istream& is) override;
    void print(ostream& os) const override;

    string get_name() const override; 

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
};

#endif
