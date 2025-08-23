 #include <iostream>
using namespace std;

// Iterative factorial function
long long factorial_iterative(int n) {
    long long result = 1;
    for(int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

// Recursive factorial function
long long factorial_recursive(int n) {
    if(n <= 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int main() {
    int number;
    cout << "Enter a non-negative integer: ";
    cin >> number;

    if(number < 0) {
        cout << "Invalid input! Please enter a non-negative integer.\n";
    } else {
        cout << "Factorial (iterative): " << factorial_iterative(number) << endl;
        cout << "Factorial (recursive): " << factorial_recursive(number) << endl;
    }

    return 0;
}
