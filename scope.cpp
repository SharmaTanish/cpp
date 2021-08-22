#include <iostream>
#include <string>
using namespace std;
// void func(string name){
//     cout<<"Global "<< name <<endl;
// }

int main(){
    string name = "Tanish";
    cout << "Local " << name << endl;

    if(name=="Tanish"){
        name="Sharma";
        // string name="Hello";
        // cout<<"local" << name << endl;
        cout<<"Global " << name << endl;
    }

    // func(name);
    return 0;
}