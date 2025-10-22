#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <cmath>
#include <string>
#include "figure.h"

class Triangle : public Figure {
public:
    Triangle();
    Triangle(double, double, double, double, double, double);
    ~Triangle() noexcept override;
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;

    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;

    pair<double, double> get_centr() const override;
    operator double() const override;
    bool eq(const Figure& other) const override;
    void read(istream& is) override;
    void print(ostream& os) const override;
    
    string get_name() const override; 
    
private:
    double x1, y1, x2, y2, x3, y3;
};

#endif
