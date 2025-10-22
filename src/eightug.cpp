#include <iostream>
#include "../include/eightug.h"

using namespace std;

Eightug::Eightug() : x1(0), x2(0), x3(0), x4(0), y1(0), y2(0), y3(0), y4(0), x5(0), y5(0), x6(0), y6(0), x7(0), y7(0), x8(0), y8(0) {}
Eightug::Eightug(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4, double a5, double b5, 
    double a6, double b6, double a7, double b7, double a8, double b8) :
    x1(a1), y1(b1), x2(a2), y2(b2), x3(a3), y3(b3), x4(a4), y4(b4), x5(a5), y5(b5), x6(a6), y6(b6), x7(a7), y7(b7), x8(a8), y8(b8) {}
Eightug::~Eightug() noexcept = default;

Eightug::Eightug(const Eightug& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4), 
    x5(other.x5), y5(other.y5), x6(other.x6), y6(other.y6), x7(other.x7), y7(other.y7), x8(other.x8), y8(other.y8) {}

Eightug::Eightug(Eightug&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4), 
    x5(other.x5), y5(other.y5), x6(other.x6), y6(other.y6), x7(other.x7), y7(other.y7), x8(other.x8), y8(other.y8) {
    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
    other.x4 = 0; other.y4 = 0;
    other.x5 = 0; other.y5 = 0;
    other.x6 = 0; other.y6 = 0;
    other.x7 = 0; other.y7 = 0;
    other.x8 = 0; other.y8 = 0;
}

Eightug& Eightug::operator=(const Eightug& other) {
    if (this == &other) return *this;
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    x5 = other.x5; y5 = other.y5;
    x6 = other.x6; y6 = other.y6;
    x7 = other.x7; y7 = other.y7;
    x8 = other.x8; y8 = other.y8;
    return *this;
}

Eightug& Eightug::operator=(Eightug&& other) noexcept {
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    x5 = other.x5; y5 = other.y5;
    x6 = other.x6; y6 = other.y6;
    x7 = other.x7; y7 = other.y7;
    x8 = other.x8; y8 = other.y8;

    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
    other.x4 = 0; other.y4 = 0;
    other.x5 = 0; other.y5 = 0;
    other.x6 = 0; other.y6 = 0;
    other.x7 = 0; other.y7 = 0;
    other.x8 = 0; other.y8 = 0;
    return *this;
}

pair<double, double> Eightug::get_centr() const {
    double centr_x = (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8) / 8;
    double centr_y = (y1 + y2 + y3 + y4 + y5 + y6 + y7 + y8) / 8;
    return {centr_x, centr_y};
}

Eightug::operator double() const {
    double square = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y6 + x6 * y7 + x7 * y8 + x8 * y1
            - y1 * x2 - y2 * x3 - y3 * x4 - y4 * x5 - y5 * x6 - y6 * x7 - y7 * x8 - y8 * x1);
    return square;
}

bool Eightug::eq(const Figure& other) const {
    const Eightug* e = dynamic_cast<const Eightug*>(&other);
    if (!e) {
        return false;
    } else {
        return (x1 == e->x1 && y1 == e->y1 &&
        x2 == e->x2 && y2 == e->y2 &&
        x3 == e->x3 && y3 == e->y3 &&
        x4 == e->x4 && y4 == e->y4 &&
        x5 == e->x5 && y5 == e->y5 &&
        x6 == e->x6 && y6 == e->y6 &&
        x7 == e->x7 && y7 == e->y7 &&
        x8 == e->x8 && y8 == e->y8);
    }
}

void Eightug::read(istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >> x7 >> y7 >> x8 >> y8;
}

void Eightug::print(ostream& os) const {
    os << "Eightug: "
        << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), "
        << "(" << x3 << ", " << y3 << "), (" << x4 << ", " << y4 << "), "
        << "(" << x5 << ", " << y5 << "), (" << x6 << ", " << y6 << "), "
        << "(" << x7 << ", " << y7 << "), (" << x8 << ", " << y8 << ")";
}

string Eightug::get_name() const {
    return "eightug";
}
