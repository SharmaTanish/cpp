// selection sort
#include <iostream>
using namespace std;

void insertionsort(int* &arr,int size){ // 8 3 5 6 20
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int index=0;
        for(int j=i-1;j>=-1;j--){
            index=j;
            if(temp<arr[j]){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            

        }
        arr[index+1]=temp;
      
      
    }
}

int main(){
    cout << "Enter size of arrays : " << endl;
    int size;
    cin >> size;
    int* arr = new int[size];

    cout << "Enter elements of array : " << endl;
    
    for(int a=0;a<size;a++){
        int ele;
        cin >> ele;
        arr[a]=ele;
    }

    insertionsort(arr,size);
    
    cout << "sorted array is : " << endl;
    for(int q=0;q<size;q++){
        cout << arr[q] << " ";
    }
}