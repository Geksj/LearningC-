#include <iostream>
#include <cmath>

int main() {
    float a, b, c;
    std::cout << "a, b, c:";
    std::cin >> a >> b >> c;
    float discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant > 1) {
        float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "x1, x2: " << x1 << ", " << x2 << std::endl;
    } else
        if (discriminant == 0) {
            float x = -b / (2 * a);
            std::cout << "x: " << x << std::endl;
        } else {
            std::cout << "Complex scenario is not supported!" << std::endl;
        }
}