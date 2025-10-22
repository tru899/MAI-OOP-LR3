#ifndef EIGHTUG_H
#define EIGHTUG_H
#include <iostream>
#include <cmath>
#include <string>
#include "figure.h"

class Eightug : public Figure {
public:
    Eightug();
    Eightug(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
    ~Eightug() noexcept override;
    Eightug(const Eightug& other);
    Eightug(Eightug&& other) noexcept;
    
    Eightug& operator=(const Eightug& other);
    Eightug& operator=(Eightug&& other) noexcept;

    pair<double, double> get_centr() const override;
    operator double() const override;
    bool eq(const Figure& other) const override;
    void read(istream& is) override;
    void print(ostream& os) const override;
    
    string get_name() const override; 

private:
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
};

#endif
