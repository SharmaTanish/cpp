#include <iostream>
using namespace std;

int main() {
  int k=50;
    int count2=0;
    while(k<=250){
    if(k%3==0  && k%5!=0){
    	count2+=k;
    }
    k++;
    }
    
    
    cout << count2 << endl;
    

  
  return 0;

}