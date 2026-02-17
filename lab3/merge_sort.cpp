#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int> &arr, int low, int high, int mid){
    int start2 = mid+1;
    int start1 = low;
    vector<int> temp;

    while(low<=mid && start2<=high){
        if(arr[low]<arr[start2]){
            temp.push_back(arr[low]);
            low++;
        }else{
            temp.push_back(arr[start2]);
            start2++;
        }

    }
    while(low<=mid){
        temp.push_back(arr[low]);
        low++;
    }
    while(start2<=high){
        temp.push_back(arr[start2]);
        start2++;
    }

    for(int i=0 ; i<=temp.size()-1 ; i++){
        arr[start1+i] = temp[i];
    }
}

void merge(vector<int> &arr, int start, int end){
    if(start>=end) return;

    int mid = start + (end-start)/2;
    merge(arr, start, mid);
    merge(arr, mid+1, end);
    mergesort(arr, start, end, mid);
}

int main(){
    vector<int> arr = {2, 3, 4, 5, 8, 11, 1};
    for(int n : arr){
        cout<<n<<' ';
    }
    cout<<endl;
    merge(arr, 0, arr.size()-1);
    for(int n : arr){
        cout<<n<<' ';
    }
}