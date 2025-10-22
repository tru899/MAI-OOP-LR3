#include <iostream>
#include "../include/triangle.h"

using namespace std;

Triangle::Triangle() : x1(0), x2(0), x3(0), y1(0), y2(0), y3(0) {}
Triangle::Triangle(double a1, double b1, double a2, double b2, double a3, double b3) :
    x1(a1), y1(b1), x2(a2), y2(b2), x3(a3), y3(b3) {}
Triangle::~Triangle() noexcept = default;

Triangle::Triangle(const Triangle& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3) {}

Triangle::Triangle(Triangle&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3) {
    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this == &other) return *this;
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;

    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
    return *this;
}

pair<double, double> Triangle::get_centr() const {
    double centr_x = (x1 + x2 + x3) / 3;
    double centr_y = (y1 + y2 + y3) / 3;
    return {centr_x, centr_y};
}

Triangle::operator double() const {
    double a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    double perimeter = (a + b + c) / 2;
    double square = sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c));
    return square;
}

bool Triangle::eq(const Figure& other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(&other);
    if (!t) {
        return false;
    } else {
        return (x1 == t->x1 && y1 == t->y1 &&
        x2 == t->x2 && y2 == t->y2 &&
        x3 == t->x3 && y3 == t->y3);
    }
}

void Triangle::read(istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
}

void Triangle::print(ostream& os) const {
    os << "Triangle: (" << x1 << ", " << y1 << "), ("
        << x2 << ", " << y2 << "), ("
        << x3 << ", " << y3 << ")";
}

string Triangle::get_name() const {
    return "triangle";
}
