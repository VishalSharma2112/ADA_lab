#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> arr, int num, int start, int end){
    if(start>end){
        return false;
    }
    int mid = start + (end - start) / 2;

    if(arr[mid]==num){
        return true;
    }else if(num<arr[mid]){
        binarySearch(arr, num, start, mid-1);
    }else{
        binarySearch(arr, num, mid+1, end);
    }
    return false;
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 6};
    int num;
    cout<<"enter the number you want to search :- ";
    cin>>num;
    bool statement = binarySearch(arr, num, 0, arr.size()-1);
    cout<<statement;
    return 0;
}
