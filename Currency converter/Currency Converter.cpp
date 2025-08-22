#include <iostream>
#include <map>
#include <string>
#include <iomanip>  // for setprecision

using namespace std;

// Function to convert currency
double convertCurrency(double amount, double exchangeRate) {
    return amount * exchangeRate;
}

int main() {
    // Exchange rates for USD as the base currency
    map<string, double> exchangeRates = {
        {"USD", 1.0},     // USD to USD (Base Currency)
        {"EUR", 0.91},    // USD to EUR
        {"GBP", 0.78},    // USD to GBP
        {"INR", 83.14},   // USD to INR
        {"AUD", 1.48},    // USD to AUD
        {"CAD", 1.36},    // USD to CAD
        {"JPY", 144.17},  // USD to JPY
        {"INR", 83.14}    // USD to INR (Indian Rupee)
    };

    string fromCurrency, toCurrency;
    double amount;

    // Input the currency you want to convert from
    cout << "Enter the source currency (USD, EUR, GBP, INR, AUD, CAD, JPY): ";
    cin >> fromCurrency;

    // Input the currency you want to convert to
    cout << "Enter the target currency (USD, EUR, GBP, INR, AUD, CAD, JPY): ";
    cin >> toCurrency;

    // Input the amount to convert
    cout << "Enter the amount: ";
    cin >> amount;

    // Check if the currency codes are valid
    if (exchangeRates.find(fromCurrency) == exchangeRates.end() || exchangeRates.find(toCurrency) == exchangeRates.end()) {
        cout << "Invalid currency code!" << endl;
        return 1;
    }

    // Convert the amount to USD first
    double amountInUSD = amount / exchangeRates[fromCurrency];

    // Convert from USD to the target currency
    double convertedAmount = convertCurrency(amountInUSD, exchangeRates[toCurrency]);

    // Output the result
    cout << fixed << setprecision(2);  // Format the output to two decimal places
    cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << endl;

    return 0;
}
