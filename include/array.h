#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <vector>
#include "figure.h"

using namespace std;

class Array {
public:
    Array() = default;
    ~Array();

    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;

    void add_to_arr(Figure* f);
    void del_from_arr(size_t idx);
    double get_total_sqr() const;
    void print_get_centr_and_square() const;
    void print_total() const;
    size_t size() const;

private:
    vector<Figure*> figures;
};

#endif
