#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 30); // 0..30 inclusive

    std::cout << "Guess the number (0-30) with difficulty levels\n";
    std::cout << "1) Easy (10 tries)\n2) Medium (7 tries)\n3) Hard (5 tries)\nChoose: ";

    int choice;
    if (!(std::cin >> choice)) return 0;

    int tries = (choice == 1 ? 10 : choice == 2 ? 7 : 5); // default hard if not 1/2
    int secret = dist(gen);

    for (int left = tries; left > 0; --left) {
        std::cout << "Enter guess (" << left << " left): ";
        int g;
        if (!(std::cin >> g)) return 0;

        if (g == secret) {
            std::cout << "Well played! " << secret << " is correct.\n";
            return 0;
        } else if (g < secret) {
            std::cout << "Too low.\n";
        } else {
            std::cout << "Too high.\n";
        }
    }
    std::cout << "Out of tries. The number was " << secret << ".\n";
    return 0;
}
