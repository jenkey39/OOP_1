#include "array.h"
#include <cmath>
#include <algorithm>


Array::Array() : data(nullptr), size(0) {}

Array::Array(size_t n, number value) : size(n) {
    data = new number[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = value;
    }
}

Array::~Array() {
    delete[] data;
}

void Array::resize(size_t newSize) {
    number* newData = new number[newSize];
    size_t minSize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

void Array::input(std::istream& in) {
    for (size_t i = 0; i < size; ++i) {
        in >> data[i];
    }
}

void Array::output(std::ostream& out) const {
    for (size_t i = 0; i < size; ++i) {
        out << data[i] << " ";
    }
    out << std::endl;
}

number Array::mean() const {
    number sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

number Array::std_dev() const {
    number avg = mean();
    number sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += (data[i] - avg) * (data[i] - avg);
    }
    return std::sqrt(sum / size);
}

void Array::sort_ascending() {
    std::sort(data, data + size);
}

void Array::sort_descending() {
    std::sort(data, data + size, std::greater<number>());
}

void Array::set_value(size_t index, number value) {
    if (index < size) {
        data[index] = value;
    }
}

number Array::get_value(size_t index) const {
    if (index < size) {
        return data[index];
    }
    return 0;
}

size_t Array::get_size() const {
    return size;
}

