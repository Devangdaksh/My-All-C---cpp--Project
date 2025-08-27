# 🌡️ Temperature Conversion (C++)
![C++ Language](https://img.shields.io/badge/Language-C++-blue)


Convert between Celsius, Fahrenheit, and Kelvin with a simple, interactive console program.  
Supports C→F, F→C, and C/F→K conversions with input validation.  



Celsius: $$ \text{°F} = \text{°C} \times 1.8 + 32 $$
- 🔁 Convert to Celsius from Fahrenheit: $$ \text{°C} = (\text{°F} - 32) \times \frac{5}{9} $$
- 🔁 Convert to Kelvin from Celsius/Fahrenheit:
  - From °C: $$ K = \text{°C} + 273.15 $$
  - From °F: $$ K = (\text{°F} - 32) \times \frac{5}{9} + 273.15 $$
- 🛡️ Basic input validation for unit selection and numeric input

## 📁 File
- Temperature-Converstion.cpp

## 📦 Requirements
- A C++ compiler (C++11+; recommended C++17)
  - GCC, Clang, or MSVC
- Terminal/Command Prompt

## 🛠️ Build
GCC/Clang:
- g++ Temperature-Converstion.cpp -std=gnu++17 -O2 -Wall -Wextra -o TempConv

MSVC (Developer Command Prompt):
- cl /EHsc /std:c++17 Temperature-Converstion.cpp

Optional debug flags:
- g++ Temperature-Converstion.cpp -std=gnu++17 -O0 -g -Wall -Wextra -Wpedantic -fsanitize=address,undefined -o TempConv

## ▶️ Run
- Linux/macOS: ./TempConv
- Windows: .\TempConv.exe

## 🧑‍💻 Usage
1) Choose the target unit:
```
Temperature conversion
C = Celsius
F = Fahrenheit
K = Kelvin
What unit would you like to convert to (C/F/K): F
```
2) Follow prompts for the source temperature:
- To Fahrenheit (from Celsius):
```
Enter temperature in Celsius: 25
Temperature in Fahrenheit: 77 °F
```
- To Celsius (from Fahrenheit):
```
Enter temperature in Fahrenheit: 98.6
Temperature in Celsius: 37 °C
```
- To Kelvin (from C/F):
```
Convert to Kelvin from (C/F): C
Enter temperature in Celsius: 0
Temperature in Kelvin: 273.15 K
```

## 🧭 Notes
- Inputs are case-insensitive for unit selection; both c/C, f/F, k/K are accepted.
- Kelvin does not accept Kelvin as the direct source in this version; select C or F first.
- The program prints an error for invalid unit or non-numeric input and exits.

## 🧱 Known Issues To Fix In Code
If the source file currently contains compilation errors, ensure the following:
- Include headers:
  - #include <iostream>
  - #include <cctype>
- Properly cast for std::toupper with unsigned char and char casts.
- Close all braces in if/else blocks and after main.
- Print results only after a successful read.

Example fixed snippet for unit normalization:
```cpp
char unit;
std::cin >> unit;
unit = static_cast<char>(std::toupper(static_cast<unsigned char>(unit)));
```

## 🗺️ Roadmap
- Add Kelvin as a source (K→C, K→F).
- Loop mode for multiple conversions without restarting.
- Precision control with iomanip and unit-aware formatting.
- Robust error handling with re-prompts.

## 🤝 Contributing
- Fork the repo
- Create a branch: feature/your-feature
- Commit with clear messages
- Open a PR with description and sample runs

## 🙌 Acknowledgements
- C++ Standard Library for I/O and character utilities
- Classic conversion formulas used in education and engineering contexts