#include <iostream>
#include "task1.h"

void task1() {
    int packages[12][3];

    for(int i = 0; i < 12; i++) {
        if(i > 1) {
            packages[i][0] = 3;
            packages[i][1] = 2;
            packages[i][2] = 1;
            continue;
        }

        packages[i][0] = 4;
        packages[i][1] = 3;
        packages[i][2] = 1;
    }

    // Приставлен +1 стол для ребенка
    packages[4][2] += 1;

    // С 3 места 2 ряда украдена ложка
    packages[8][0] -= 1;

    // Vip-гость поделился ложкой
    packages[0][0] -= 1;
    packages[4][2] += 1;

    // Убрана десертная тарелка
    packages[0][1] -= 1;
}
