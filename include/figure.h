#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <string>
using namespace std;

class Figure {

public:
    Figure() = default;
    Figure(const Figure& other) = default;
    Figure(Figure&& other) noexcept = default;
    virtual ~Figure() = default;

    virtual bool eq(const Figure& other) const = 0;
    virtual pair<double, double> get_centr() const = 0;
    virtual operator double() const = 0;
    virtual void read(istream&) = 0;
    virtual void print(ostream&) const = 0;

    virtual string get_name() const = 0;
};

inline istream& operator>>(istream& is, Figure& f) {
    f.read(is);
    return is;
}

inline ostream& operator<<(ostream& os, const Figure& f) {
    f.print(os);
    return os;
}

inline bool operator==(const Figure& lhs, const Figure& rhs) {
    return lhs.eq(rhs);
}

#endif
