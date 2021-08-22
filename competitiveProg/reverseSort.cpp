#include <iostream>
using namespace std;

int main(){
    
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    int arr[size];     
    cout <<  "Enter array elements : " ; 
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    for(int i=0;i<size-1;i++){
        int min=10000;
        int min_index=i;
        for(int j=i;j<size;j++){
            if(arr[j]<min){
                min=arr[j];
                min_index=j;
            }
        }
        int q=0;
        for(int k=i;k<min_index-q;k++){
            int temp = arr[min_index-q];
            arr[min_index-q]=arr[k];
            arr[k]=temp;
            q++;
        }

    }
    cout << "Sorted array is : ";
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }

}


// IN PLACE OF " " IF WRITE ENDL THEN COMING SOME GARBAGE VALUES 😭