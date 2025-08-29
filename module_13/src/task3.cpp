#include <iostream>
#include <vector>
#include "task3.h"

void print(const std::vector<int>& v, signed int start, signed int end) {

    std::cout << "output: ";

    while(start != end) {
        std::cout << v[start++] << " ";

        if(start > v.size()) {
            start = 0;
        }
    }

    std::cout << std::endl;
}

void task3() {
    std::vector<int> db(20);
    int el = 0;
    signed int start = 0;
    signed int end = start;
    bool circle = false;

    while(el >= -1) {
        std::cout << "Input element: ";
        std::cin >> el;

        if(start == db.size()) {
            start = 0;
        }

        if(end > db.size()) {
            end = start;
            circle = true;
        }

        if(end == start && circle) {
            ++start;
        }

        if(el == -1) {
            print(db, start, end);
            continue;
        }

        if(el >= 0) {
            db[end++] = el;
        }
    }

    std::cout << "The program is completed" << std::endl;
    print(db, start, end);
};