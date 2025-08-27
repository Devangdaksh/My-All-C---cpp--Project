#include <iostream>
#include <cmath>

int main() {
    double a;
    double b;

    std::cout << "Enter side a: ";
    std::cin >> a;
    std::cout << "Enter side b: ";
    std::cin >> b;

    if (!std::cin || a < 0 || b < 0) {
        std::cout << "Invalid input. Please enter non-negative numbers.\n";
        return 0;
    }

    double c = std::hypot(a, b);

    std::cout << "side c: " << c << "\n";
    return 0;
}
