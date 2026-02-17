#include <iostream>
using namespace std;

double horner(double coeffs[], int n, double x) {
    double result = coeffs[0]; 

    for (int i = 1; i < n; i++) {
        result = result * x + coeffs[i];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of coefficients: ";
    cin >> n;

    double coeffs[n];
    cout << "Enter coefficients (highest degree first): ";
    for (int i = 0; i < n; i++) {
        cin >> coeffs[i];
    }

    double x;
    cout << "Enter value of x: ";
    cin >> x;

    double value = horner(coeffs, n, x);
    cout << "Polynomial value = " << value << endl;

    return 0;
}
