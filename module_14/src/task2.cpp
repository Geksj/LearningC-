#include <iostream>
#include "task2.h"

void print(const char (&field)[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printErr(const std::string& text) {
    std::cout << text << std::endl;
    std::cout << "Repeat the input: " << std::endl;
}

bool isValidCoordinate(const int& x, const int& y, const char (&field)[3][3]) {
    if(!((x >= 0 && x < 3) && (y >= 0 && y < 3))) {
        printErr("Invalid input");
        return false;
    }

    if(field[x][y] != '*') {
        printErr("Field is not empty");
        return false;
    }

    return true;
}

void inputCoordinate(int& x, int& y, std::string player) {
    std::cout << "The " << player << " player's move(x y): " << std::endl;
    std::cin >> x >> y;
}

bool isVictory(const char (&field)[3][3]) {
    bool flag = true;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j + 1 < 3; j++) {
            if(field[i][j] == '*') {
                flag = false;
                break;
            }
            flag = field[i][j] == field[i][j + 1] ? true : false;
        }
        if(flag) {
            return flag;
        }
    }

    if(!flag) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j + 1 < 3; j++) {
                if(field[j][i] == '*') {
                    flag = false;
                    break;
                }
                flag = field[j][i] == field[j + 1][i] ? true : false;
            }
            if(flag) {
                return flag;
            }
        }
    }

    return flag;
}

void checkOnVictory(char (&field)[3][3], int& emptyField) {
    if(emptyField < 5) {
        if (isVictory(field)) {
            if(emptyField % 2 == 0) {
                std::cout << "Victory first player" << std::endl;
            } else {
                std::cout << "Victory second player" << std::endl;
            }
            emptyField = -1;
        }
    }
}

void fillingEmptyValues(char (&arr)[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            arr[i][j] = '*';
        }
    }
}

void task2() {
    char field[3][3];
    int emptyField = 9;
    int x, y;

    fillingEmptyValues(field);

    while(0 < emptyField) {
        print(field);
        checkOnVictory(field, emptyField);
        if (emptyField == -1) return;

        if(emptyField % 2 == 0) {
            inputCoordinate(x, y, "second");

            if(isValidCoordinate(x, y, field)) {
                field[x][y] = 'O';
                emptyField -= 1;
            }

            continue;
        }

        inputCoordinate(x, y, "first");

        if(isValidCoordinate(x, y, field)) {
            field[x][y] = 'X';
            emptyField -= 1;
        }
    }

    std::cout<< "DRAW" << std::endl;

}