
#include <iostream>
using namespace std;
int main(){
    int num=41;
    for(int i=2;i<num;i++){
        if(num%i==0){
            cout << "Number is not prime";
            return 0;
        }
    }
    cout << "Number is prime";
    return 0;
}