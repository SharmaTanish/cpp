// selection sort
#include <iostream>
#include <string>
using namespace std;

void selectionsort(char arr[],int size){
    for(int i=0;i<size;i++){
        int min=arr[i];
        int minIndex=i;
        for(int j=i;j<size;j++){
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }
        }
      
        arr[minIndex]=arr[i];
        arr[i]=min;

    }
}


int main(){
    // cout << "Enter size of arrays : " << endl;
    // int size;
    // cin >> size;
    // int* arr = new int[size];

    // cout << "Enter elements of array : " << endl;
    
    // for(int a=0;a<size;a++){
    //     int ele;
    //     cin >> ele;
    //     arr[a]=ele;
    // }

    // selectionsort(arr,size);
    
    // cout << "sorted array is : " << endl;
    // for(int q=0;q<size;q++){
    //     cout << arr[q] << " ";
    // }

    string str = "tanish";
    
    // int arr[] = {0,9,4,6,20};
    // size =sizeof(arr)/sizeof(arr[0]);
    char arr[str.size()];
    for(int i=0;i<str.size();i++){
        arr[i]=str[i];
    }
    selectionsort(arr,str.size());
    for(int q=0;q<str.size();q++){
        cout << arr[q] << " ";
    }
}