#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int xorArr = 0;
    int xorFull = 0;

    // XOR of array
    for (int i = 0; i < n; i++)
        xorArr ^= arr[i];

    // XOR of 1 to n+1
    for (int i = 1; i <= n + 1; i++)
        xorFull ^= i;

    return xorArr ^ xorFull;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findMissing(arr, n);
}
