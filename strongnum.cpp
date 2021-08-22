
#include <iostream>
using namespace std;
int main(){
    int num=145;
    int factsum=0;
    int temp=num;
    while(temp>0){
        int digit=temp%10;
        int fact=1;
        for(int i=1;i<=digit;i++){
            fact*=i;
        }
        factsum+=fact;
        temp=temp/10;
    }

    if(factsum==num){
        cout << "Number is Strong number";
    }
    else{
        cout << "Number is not a strong number";
    }

    return 0;
}