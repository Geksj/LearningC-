#include <iostream>
#include <vector>
#include "task1.h"

void task1() {
    signed int size;
    int delNumber;

    std::cout << "Input vector size: ";
    std::cin >> size;

    if(size <= 0) {
        std::cout << "Invalid vector size." << std::endl;
        return;
    }

    std::vector<int> v(size);

    std::cout << "Input numbers: ";
    for(int i = 0; i < v.size(); ++i) {
        std::cin >> v[i];
    }

    std::cout << "Input number to delete:" << std::endl;
    std::cin >> delNumber;

    for(int i = v.size() - 1; i >= 0; --i) {
        if(v[i] == delNumber) {
            int temp = v[i];
            for(int j = i; j < v.size() - 1; ++j) {
                v[j] = v[j + 1];
            }
            v[v.size() - 1] = temp;
            v.pop_back();
        }
    }

    std::cout << "Result: ";
    for(int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
}