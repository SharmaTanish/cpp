// #include<iostream> 

// int main()
// {
//     cout << "Hello world" << endl;
//     return 0;
// }



#include <iostream>
using namespace std;

int main() 
{

  for(int i=0;i<10;i++){
	cout << "Tanish"<<endl;
}


cout << "----------------------------------------" << endl;
////////////////////////////////////

  for(int i=0;i<100;i++){
	if(i%2==0){
    	cout << i << endl;
    }
    }
    
    cout << "----------------------------------------" << endl;
    /////////////////////////////
    
    int i=50;
    int count=0;
    while(i<=250){
    if(i%3==0){
    	count+=i;
    }
    i++;
    }
    
    
    cout << count << endl;
    
    cout << "----------------------------------------" << endl;
    //////////////////////////////////


    int j=50;
    int count1=0;
    do{
    if(j%3==0){
    	count1+=j;
    }
    j++;
    }
    while(j<=250);
    
    
    cout << count1 << endl;
    
    cout << "----------------------------------------" << endl;
    ///////////////////////////////////
    
    
    int k=1;
    int count2=0;
    while(k<=100){
    if(k%3==0  && k%5!=0){
    	count2+=k;
    }
    k++;
    }
    
    
    cout << count2 << endl;
    

  
  return 0;  // CAN RETURN ANY INTEGER
}