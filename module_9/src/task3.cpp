#include <iostream>
#include "task3.h"

void task3() {
    std::string input, temp;
    signed int count = 0;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if(input.empty()) {
        std::cout << 0 << std::endl;
        return;
    }

    for(int i = 0; i < input.length(); i++) {
        if(input[i] == ' ') {
            if(!temp.empty()) {
                count++;
                temp.clear();
            }
            continue;
        }

        temp += input[i];
    }

    if (input[input.length() - 1] != ' ') {
        count++;
    }

    std::cout << count << std::endl;
}