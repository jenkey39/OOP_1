#include "application.h"
#include <iostream>

void Application::run() {
    bool running = true;
    while (running) {
        print_menu();
        int command;
        std::cin >> command;
        switch (command) {
        case 1: handle_input(); break;
        case 2: handle_mean_and_stddev(); break;
        case 3: handle_sort(true); break;
        case 4: handle_sort(false); break;
        case 5: handle_resize(); break;
        case 6: handle_modify_element(); break;
        case 7: handle_output(); break;
        case 0: running = false; break;
        default: std::cout << "Неверная команда!" << std::endl; break;
        }
    }
}

void Application::print_menu() const {
    std::cout << "Меню команд:\n"
              << "1. Ввод массива\n"
              << "2. Среднее и СКО\n"
              << "3. Сортировка по возрастанию\n"
              << "4. Сортировка по убыванию\n"
              << "5. Изменение размерности массива\n"
              << "6. Изменение элемента массива\n"
              << "7. Вывод массива\n"
              << "0. Выход\n"
              << "Введите команду: ";
}

void Application::handle_input() {
    size_t size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    array.resize(size);
    std::cout << "Введите элементы массива: ";
    array.input(std::cin);
}

void Application::handle_mean_and_stddev() {
    std::cout << "Среднее: " << array.mean() << "\n"
              << "СКО: " << array.std_dev() << std::endl;
}

void Application::handle_sort(bool ascending) {
    if (ascending) {
        array.sort_ascending();
        std::cout << "Массив отсортирован по возрастанию." << std::endl;
    } else {
        array.sort_descending();
        std::cout << "Массив отсортирован по убыванию." << std::endl;
    }
}

void Application::handle_resize() {
    size_t newSize;
    std::cout << "Введите новый размер массива: ";
    std::cin >> newSize;
    array.resize(newSize);
}

void Application::handle_modify_element() {
    size_t index;
    number value;
    std::cout << "Введите индекс элемента: ";
    std::cin >> index;
    std::cout << "Введите новое значение элемента: ";
    std::cin >> value;
    array.set_value(index, value);
}

void Application::handle_output() const {
    std::cout << "Элементы массива: ";
    array.output(std::cout);
}
