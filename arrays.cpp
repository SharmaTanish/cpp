#include <iostream>
using namespace std;

// addition of 10 numbers-----------------------

// int main(){
//  int arr[10];
//  cout <<  "Enter array elements : " ; 
//  for(int i=0;i<10;i++){
//     cin >> arr[i];
// }
// int sum=0;
// for(int i=0;i<10;i++){
//     sum+=arr[i];

// }
// cout << sum;
// return 0;
// }

//////////////////////////////////////////////////////////////

// print address of elements of array-----------------------------

// int main(){
//  int arr[10];
//     cout <<  "Enter array elements : " ; 
//  for(int i=0;i<10;i++){
//     cin >> arr[i];
// }
// cout <<  "Enter element which address you want : " ;
// int a;
// cin >> a; 


// for(int i=0;i<10;i++){
//     if(arr[i] == a){
//     cout << "Address of " << i << "th element in array " << &arr[i] << endl;

//     }
// }

// return 0;
// }


////////////////////////////////////////////////////////////////////

// print even elements of array withih given range----------------------

// int main(){
// int size;
// cout << "Enter size of array ";
// cin >> size;

//  int arr[size];      // YEH WORK KAR RAHA HAI , VSCODE FALTU MAI APNE INTELLISENSE KI VAGAH SE ERROR DIKHA RAHA HAI, DIRECT RUN KARKE CPP COMPILER MAI KOI ERROR NAHI HAI! 

// cout <<  "Enter array elements : " ; 
//  for(int i=0;i<size;i++){
//     cin >> arr[i];
// }
// int sum=0;
// int min;
// cout << "Enter minimum value of range"<< endl;
// cin >> min;
// int max;
// cout << "Enter maximum value of range"<< endl;
// cin >> max;

// for(int i=0;i<size;i++){
//     if(arr[i]%2==0 && arr[i]>=min && arr[i]<=max){
//     sum+=arr[i];
//     }

// }
// cout << sum;
// return 0;
// }



///////////////////////////////////////////////////////////

// insertion at beginning of array

// int main(){

// int arr[4] = {2,3,4,5};

// int size;
// cout << "Enter size of array ";
// cin >> size;

//  int arr[size];     
// cout <<  "Enter array elements : " ; 
//  for(int i=0;i<size;i++){
//     cin >> arr[i];
// }

// int num;
// cout << "Enter element which you want to insert in beginning : ";
// cin >> num;

// int arr1[size+1];

// arr1[0]=num;
// for(int i=0;i<size;i++){
//     arr1[i+1]=arr[i];
// }
// for(int i=0;i<size+1;i++){
//     cout << arr1[i] << " ";
// }

// for(int i=4;i>0;i--){
//     arr[i]=arr[i-1];
// }
// arr[0] = num;

// return 0;
// }


///////////////////////////////////////////////////////

//LINEAR SEARCH

// int main(){

// int size;
// cout << "Enter size of array : ";
// cin >> size;

//  int arr[size];     
// cout <<  "Enter array elements : " ; 
//  for(int i=0;i<size;i++){
//     cin >> arr[i];
// }

// cout << "Enter element you want to search : ";
// int ele;
// cin >> ele;
// bool flag=true;
// for(int i=0;i<size;i++){
//     if(arr[i]==ele){
//         cout << ele << " is at index " << i;
//         flag=false;
//         break;
//     }
// }
// if(flag){
//     cout << ele << " is not there exist in array!";
// }

//     return 0;
// }


///////////////////////////////////////////////////////////////////



//BINARY SEARCH

// int main(){

// int size;
// cout << "Enter size of array : ";
// cin >> size;

//  int arr[size];     
// cout <<  "Enter array elements in sorted order : " ; 
//  for(int i=0;i<size;i++){
//     cin >> arr[i];
// }

// cout << "Enter element you want to search : ";
// int ele;
// cin >> ele;

// int start =0;
// int end=size-1;
// bool flag = true;

// while(start<end){
//     int mid = (start+end)/2;
//     if(arr[mid]==ele){
//         cout << ele << " is at index " << mid;
//         flag=false;
//         break;
//     }
//     else if(ele<arr[mid]){
//         end = mid-1;
//     }
//     else if(ele>arr[mid]){
//         start=mid+1;
//     }
// }

//     if (flag){
//         cout << ele << " not there exist in array!";
//     }

//     return 0;
// }

////////////////////////////////////////////////////

// BUBBLE SORT


int main(){

int size;
cout << "Enter size of array : ";
cin >> size;

 int arr[size];     
cout <<  "Enter array elements : " ; 
 for(int i=0;i<size;i++){
    cin >> arr[i];
}

int length = size;
while(length>1){


for(int i=0;i<length-1;i++){
    if(arr[i]>arr[i+1]){
        int temp = arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=temp;
    }
}

length--;

}
cout << "Sorted array is : ";
for(int i=0;i<size;i++){
    cout << arr[i] << " ";
}

    return 0;
}




