#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, num;

    cout << "Enter how many numbers: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter number " << i << ": ";
        cin >> num;
        sum += num;
    }

    cout << "Sum = " << sum;

    return 0;
}
