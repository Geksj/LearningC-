#include <iostream>
#include "task1.h"

std::string encrypt_caesar(std::string str, int k) {
    for(int i = 0; i < str.length(); i++) {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
            continue;
        }
        int temp = str[i] + k - 26 * (k / 26);

        if(str[i] >= 'a' && str[i] <= 'z') {
            if(temp > 'z') {
                temp -= 26;
            }
        } else {
            if(temp > 'Z') {
                temp -= 26;
            }
        }
        str[i] = temp;
    }


    return str;
}

void task1() {
    std::string str;
    int k;
    std::cout << "Enter a string: ";
    std::cin >> str;

    std::cout << "Enter a key: ";
    std::cin >> k;

    if (k < 0) k = -k;

    std::cout << "Result: " << encrypt_caesar(str, k) << std::endl;
}

