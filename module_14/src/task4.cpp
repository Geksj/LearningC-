#include <iostream>
#include "task4.h"

void task4() {
    int matr[4][4];
    int vec[4];
    int res[4];

    std::cout << "Enter number for matrix: " << std::endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << "a" << i << "," << j << ": ";
            std::cin >> matr[i][j];
        }
    }

    std::cout << "Enter number for vector: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "b" << i << ": ";
        std::cin >> vec[i];
    }

    for(int i = 0; i < 4; i++) {
        int accum = 0;
        for(int j = 0; j < 4; j++) {
            accum += matr[i][j] * vec[j];
        }
        res[i] = accum;
        accum = 0;
    }

    for(int i = 0; i < 4; i++) {
        std::cout << res[i] << " ";
    }
}