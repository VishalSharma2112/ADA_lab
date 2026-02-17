#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int> arr, int num){
    for(int i=0 ; i<arr.size() ; i++){
        if(num==arr[i]){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {2, 3, 54, 6 ,7 ,71};
    int num;
    cout<<"enter the number you want to search :- ";
    cin>>num;
    cout<<linearSearch(arr, num);
}