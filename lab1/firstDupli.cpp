#include <iostream>
#include <vector>
using namespace std;

int dupliNum(vector<int> arr){
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i+1; j<arr.size() ; j++){
            if(arr[i]==arr[j]){
                return arr[j];
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 5 ,4 , 5, 6 ,8};
    cout<<dupliNum(arr);
}