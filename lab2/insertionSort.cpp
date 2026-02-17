#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

void display(vector<int> arr){
    for(int x : arr){
        cout<<x<<" ";
    }
}

int main(){
    vector<int> arr = {3, 6, 5, 8, 9, 2};
    display(insertionSort(arr));

    return 0;
}