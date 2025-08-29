#include <iostream>
#include <vector>
#include "task2.h"

void task2() {
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
    std::vector items {1, 1, 0, 3, 2, 1, 1, 1, -1, 10};
    float sum = 0;

    for(int i = 0; i < items.size(); i++) {
        if(items[i] > prices.size()) {
            std::cout << items[i] << " is greater than the size of the array" << std::endl;
            continue;
        }

        sum += prices[items[i]];
    }

    std::cout << "Sum item = " << sum << std::endl;
}