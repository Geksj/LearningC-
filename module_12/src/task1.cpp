#include <iostream>
#include "task1.h"


void task1() {
    int numberFlat = -2;
    const signed int size = 10;
    std::string tenantList[size];

    for(int i = 0; i < size; i++) {
        std::cout << "Enter name tenant: ";
        std::cin >> tenantList[i];
    }

    while(numberFlat != -1) {
        std::cout << "Enter flat numbers: ";
        std::cin >> numberFlat;

        numberFlat -= 1;

        if (numberFlat < 0 || numberFlat >= size) {
            std::cout << "Flat not found" << std::endl;
            continue;
        }

        std::cout << tenantList[numberFlat] << std::endl;
        std::cout << "If you want exit from app enter number 0" << std::endl;
    }
}