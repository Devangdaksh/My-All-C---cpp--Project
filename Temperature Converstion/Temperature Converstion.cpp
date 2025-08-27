#include <iostream>
#include <cctype>

int main() {
    double temperature;
    char unit;

    std::cout << "Temperature conversion\n";
    std::cout << "C = Celsius\n";
    std::cout << "F = Fahrenheit\n";
    std::cout << "K = Kelvin\n";
    std::cout << "What unit would you like to convert to (C/F/K): ";
    std::cin >> unit;

    unit = static_cast<char>(std::toupper(static_cast<unsigned char>(unit)));

    if (unit == 'F') {
        // Convert from Celsius to Fahrenheit
        std::cout << "Enter temperature in Celsius: ";
        if (!(std::cin >> temperature)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        double result = temperature * 1.8 + 32.0; // °F = °C * 1.8 + 32
        std::cout << "Temperature in Fahrenheit: " << result << " °F\n";
    }
    else if (unit == 'C') {
        // Convert from Fahrenheit to Celsius
        std::cout << "Enter temperature in Fahrenheit: ";
        if (!(std::cin >> temperature)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        double result = (temperature - 32.0) * 5.0 / 9.0; // °C = (°F - 32) * 5/9
        std::cout << "Temperature in Celsius: " << result << " °C\n";
    }
    else if (unit == 'K') {
        // Ask source scale for Kelvin conversion
        char from;
        std::cout << "Convert to Kelvin from (C/F): ";
        std::cin >> from;
        from = static_cast<char>(std::toupper(static_cast<unsigned char>(from)));

        if (from == 'C') {
            std::cout << "Enter temperature in Celsius: ";
            if (!(std::cin >> temperature)) {
                std::cout << "Invalid input.\n";
                return 0;
            }
            double result = temperature + 273.15; // K = °C + 273.15
            std::cout << "Temperature in Kelvin: " << result << " K\n";
        } else if (from == 'F') {
            std::cout << "Enter temperature in Fahrenheit: ";
            if (!(std::cin >> temperature)) {
                std::cout << "Invalid input.\n";
                return 0;
            }
            double result = (temperature - 32.0) * 5.0 / 9.0 + 273.15; // K = (°F - 32)*5/9 + 273.15
            std::cout << "Temperature in Kelvin: " << result << " K\n";
        } else {
            std::cout << "Unsupported source unit for Kelvin. Use C or F.\n";
        }
    }
    else {
        std::cout << "Unknown target unit. Please choose C, F, or K.\n";
    }

    return 0;
}