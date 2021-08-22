#include <iostream>
using namespace std;

// class Abc{
//     public:
//     int sum(int a, int b);
// };
//  int Abc::sum(int a, int b){
//      return a+b;
//  }

//  int main(){
//      Abc obj;
//      int out = obj.sum(5,4);
//      cout << out;
//      return 0;
//  }

/////////////////////////////////////////////////////////////////////////

class Abc{
    public:
    int func(int a, int b);
    double func(int a, double b);

};
 int Abc::func(int a, int b){
     return a+b;
 }
double Abc::func(int a, double b){
     return a+b;
 }
 int main(){
     Abc obj;
     int out1 = obj.func(5,4);
     double out2 = obj.func(5,4.5);

     cout << out1 << endl;
     cout << out2;

     return 0;
 }