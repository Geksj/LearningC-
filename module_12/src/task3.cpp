#include <iostream>
#include <cassert>
#include "task3.h"

float travelTime(float distance, float speed) {
    assert(distance > 0);
    assert(speed > 0);
    return distance / speed;
}

void task3() {
    float distance, speed;
    std::cout << "Enter distance travel speed: ";
    std::cin >> distance >> speed;

    std::cout << travelTime(distance, speed);
}