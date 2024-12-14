#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "number.h"

class Array {
private:
    number* data;
    size_t size;
public:
    Array();
    Array(size_t n, number value = 0);
    ~Array();
    void resize(size_t newSize);
    void input(std::istream& in);
    void output(std::ostream& out) const;
    number mean() const;
    number std_dev() const;
    void sort_ascending();
    void sort_descending();
    void set_value(size_t index, number value);
    number get_value(size_t index) const;
    size_t get_size() const;
};

#endif
