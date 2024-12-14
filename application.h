#ifndef APPLICATION_H
#define APPLICATION_H

#include "array.h"

class Application {
private:
    Array array;

public:
    void run();
private:
    void print_menu() const;
    void handle_input();
    void handle_mean_and_stddev();
    void handle_sort(bool ascending);
    void handle_resize();
    void handle_modify_element();
    void handle_output() const;
};

#endif // APPLICATION_H
