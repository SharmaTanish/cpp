#include <iostream>
using namespace std;

int func(int a,int b){
    return a+b;
}
int func(int a,float b){
    return a-b;
}
int func(int a){
    return a*10;
}

int main(){
    int a=55;;
    // cin >> a;
    float b=20.5;
    // cin >> b;
    int c=5;
    // cin >> c;
    int out1 = func(a,c);
    int out2 = func(a,b);
    int out3 = func(a);
    cout << out1<<" Sum" <<endl;
    cout << out2<<" subs"<<endl;
    cout << out3<<" mult"<<endl;
    return 0;
}

