#include <iostream>
using namespace std;

void radixSort(int arr[],int maxDigitSize){
    int count = 1;
    while(count<=maxDigitSize){
    for(int i=0;i<7;i++){
        int* arr1 = new int[7];
        
            arr1[i]=arr1[i]/10;
        
    }
    }
}

int main(){
    int arr[] = {45,50,82,16,2,38,57};
    radixSort(arr,2);
    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
    return 0;
}