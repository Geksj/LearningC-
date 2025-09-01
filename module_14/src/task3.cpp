#include <iostream>
#include "task3.h"

void inputMatrix(int (&matr)[4][4], char s) {
    std::cout << "Enter number for matrix "<< s << ":" << std::endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << s << i << "," << j << ": ";
            std::cin >> matr[i][j];
        }
    }
}

void print(const int (&matr)[4][4], char s) {
    std::cout << "Matrix " << s << std::endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (matr[i][j] > -1 && matr[i][j] < 10) {
                std::cout << matr[i][j] << "  ";
            } else {
                std::cout << matr[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void transformMatrix(int (&matr)[4][4]) {
    int k = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == k && j == k) {
                k++;
                continue;
            }
            matr[i][j] = 0;
        }
    }
}

void task3() {
    int a[4][4];
    int b[4][4];

    inputMatrix(a, 'A');
    inputMatrix(b, 'B');

    print(a, 'A');
    print(b, 'B');

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(a[i][j] != b[i][j]) {
                std::cout << "The matrix are not equal" << std::endl;
                return;
            }
        }
    }
    std::cout << "The matrix are equal" << std::endl;

    transformMatrix(a);

    std::cout << "The matrix A transformed" << std::endl;
    print(a, 'A');

}