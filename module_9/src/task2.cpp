#include <iostream>
#include "task2.h"

bool isValid(std::string str) {
    bool hasDot = false;
    int start = 0;

    if(str[0] == '-') {
        if((str[1] < '0' || str[1] > '9') && str[1] != '.') {
            std::cerr << "Non numb after -" << std::endl;
            return false;
        }

        start = 1;
    }

    if(str[0] == '.') {
        if(str[1] < '0' || str[1] > '9') {
            std::cerr << "Non numb after ." << std::endl;
            return false;
        }

        start = 1;
        hasDot = true;
    }

    for(int i = start; i < str.length(); i++) {
        if(str[i] == '.') {
            if (hasDot) {
                std::cerr << "Double ." << std::endl;
                return false;
            } else {
                hasDot = true;
            }
        }

        if((str[i] < '0' || str[i] > '9') && str[i] != '.') {
            std::cerr << i << " Non number" << std::endl;
            return false;
        }
    }

    return true;
}

void task2() {
    std::string numb;

    std::cout << "Enter a real number: ";
    std::cin >> numb;

    if(isValid(numb)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
}