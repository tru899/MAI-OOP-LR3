#include <iostream>
#include "../include/square.h"

using namespace std;

Square::Square() : x1(0), x2(0), x3(0), y1(0), y2(0), y3(0), x4(0), y4(0) {}
Square::Square(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4) :
    x1(a1), y1(b1), x2(a2), y2(b2), x3(a3), y3(b3), x4(a4), y4(b4) {}
Square::~Square() noexcept = default;

Square::Square(const Square& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Square::Square(Square&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
    other.x4 = 0; other.y4 = 0;
}

Square& Square::operator=(const Square& other) {
    if (this == &other) return *this;
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;

    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
    other.x4 = 0; other.y4 = 0;
    return *this;
}

pair<double, double> Square::get_centr() const {
    double centr_x = (x1 + x2 + x3 + x4) / 4;
    double centr_y = (y1 + y2 + y3 + y4) / 4;
    return {centr_x, centr_y};
}

Square::operator double() const {
    double square = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - y1 * x2 - y2 * x3 - y3 * x4 - y4 * x1); //Gauss formula univ mnogoug
    return square;
}

bool Square::eq(const Figure& other) const {
    const Square* s = dynamic_cast<const Square*>(&other);
    if (!s) {
        return false;
    } else {
        return (x1 == s->x1 && y1 == s->y1 &&
        x2 == s->x2 && y2 == s->y2 &&
        x3 == s->x3 && y3 == s->y3 &&
        x4 == s->x4 && y4 == s->y4);
    }
}

void Square::read(istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

void Square::print(ostream& os) const {
    os << "Square: ("
        << x1 << ", " << y1 << "), ("
        << x2 << ", " << y2 << "), ("
        << x3 << ", " << y3 << "), ("
        << x4 << ", " << y4 << ")";
}

string Square::get_name() const {
    return "kvadrat";
}
