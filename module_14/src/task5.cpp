#include <iostream>
#include "task5.h"

void init(bool (&bubbleWrap)[12][12]) {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            bubbleWrap[i][j] = true;
        }
    }
}

void print(bool (&bubbleWrap)[12][12]) {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            if(bubbleWrap[i][j]) {
                std::cout << "o" << " ";
                continue;
            }
            std::cout << "x" << " ";
        }
        std::cout << std::endl;
    }
}

void inputCoordinatesForBubbles(int& x, int& y, std::string text) {
    std::cout << "Enter " << text << " x, y: " << std::endl;
    std::cin >> x >> y;
}

bool isValidInput(int& x1, int& y1, int& x2, int& y2) {
    if (x1 > x2 && y1 > y2) {
        std::cout << "The coordinate end > start" << std::endl;
        return false;
    }

    if(x1 < 0 || y1 < 0 || x1 >= 12 || y1 >= 12) {
        std::cout << "Start`s coordinate inValid!" << std::endl;
        return false;
    }

    if (x2 < 0 || y2 < 0 || x2 >= 12 || y2 >= 12) {
        std::cout << "End`s coordinate inValid!" << std::endl;
        return false;
    }

    return true;
}

int pop(bool (&bubbleWrap)[12][12], int& x1, int& y1, int& x2, int& y2) {
    int count = 0;
    int j = y1;
    for(int i = x1; i <= x2; i++) {
        for(; j < 12; j++) {
            if((i == x2) && (j == y2 + 1)) return count;
            if (!bubbleWrap[i][j]) continue;

            bubbleWrap[i][j] = false;
            std::cout << "POP" << std::endl;
            count++;
        }
        j = 0;
    }

    return count;
}

void task5() {
    bool bubbleWrap[12][12];
    int wholeBubble = 144;
    int x1, y1, x2, y2;

    init(bubbleWrap);


    while(wholeBubble > 0) {
        print(bubbleWrap);
        inputCoordinatesForBubbles(x1, y1, "start");
        inputCoordinatesForBubbles(x2, y2, "end");

        if(!isValidInput(x1, y1, x2, y2)) continue;

        wholeBubble -= pop(bubbleWrap, x1, y1, x2, y2);
    }

    print(bubbleWrap);
}