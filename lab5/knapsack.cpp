#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int profit;
};

bool compare(Item a, Item b, int method) {
    if(method == 1)          // Sort by weight (ascending)
        return a.weight < b.weight;

    else if(method == 2)     // Sort by profit (descending)
        return a.profit > b.profit;

    else                     // Sort by profit/weight ratio (descending)
        return (double)a.profit/a.weight > (double)b.profit/b.weight;
}

void merge(vector<Item>& arr, int left, int mid, int right, int method) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Item> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(compare(L[i], R[j], method))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<Item>& arr, int left, int right, int method) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, method);
        mergeSort(arr, mid + 1, right, method);

        merge(arr, left, mid, right, method);
    }
}

double fractionalKnapsack(vector<Item> items, int capacity, int method) {

    mergeSort(items, 0, items.size() - 1, method);

    double totalProfit = 0.0;

    for(int i = 0; i < items.size(); i++) {

        if(capacity == 0)
            break;

        if(items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            double fraction = (double)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            capacity = 0;
        }
    }

    return totalProfit;
}

int main() {

    vector<Item> items = {
        {5, 30},
        {10, 40},
        {15, 45},
        {22, 77},
        {25, 90},
        {30, 120}
    };

    int capacity = 50;

    cout << "Profit (Sort by Weight) = "
         << fractionalKnapsack(items, capacity, 1) << endl;

    cout << "Profit (Sort by Profit) = "
         << fractionalKnapsack(items, capacity, 2) << endl;

    cout << "Profit (Sort by Profit/Weight) = "
         << fractionalKnapsack(items, capacity, 3) << endl;

    return 0;
}