#include "array.h"
#include <iostream>
using namespace std;

Array::~Array() {
    for (Figure* f : figures) {
        delete f;
    }
}

void Array::add_to_arr(Figure* f) {
    figures.push_back(f);
}

void Array::del_from_arr(size_t idx) {
    if (figures.empty()) {
        cout << "array is empty\n";
        return;
    }
    
    if (idx >= figures.size()) {
        cout << "error: idx " << idx << " out of range. valid range is 0-" << (figures.size() - 1) << "\n";
        return;
    }
    
    delete figures[idx];
    figures.erase(figures.begin() + idx);
}

double Array::get_total_sqr() const {
    double total = 0;
    for (const auto& f : figures) {
        total += static_cast<double>(*f);
    }
    return total;
}

void Array::print_get_centr_and_square() const {
    if (figures.empty()) {
        cout << "array is empty\n";
        return;
    }
    for (const auto& f : figures) {
        cout << f->get_name() << " info: "; 
        auto [x, y] = f->get_centr();
        cout << "centr: (" << x << ", " << y << "), ";
        cout << "square: " << static_cast<double>(*f) << endl;
    }
}

void Array::print_total() const {
    cout << "total square: " << get_total_sqr() << endl;
}

size_t Array::size() const {
    return figures.size();
}
