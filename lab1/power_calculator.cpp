#include <iostream>
using namespace std;

int powerNum(int num, int pow){
    if(pow==0){
        return 1;
    }

    return num*powerNum(num, pow-1);
}

int main(){
    cout<<"enter the number :- ";
    int num;
    cin>>num;
    cout<<endl<<"enter the power :- ";
    int pow;
    cin>>pow;
    cout<<powerNum(num, pow);
}