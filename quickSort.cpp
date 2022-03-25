#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei){
    int i = si;
    int j=ei;
    int pivot = arr[si];
    int count=0;
    for(int q=si;q<=ei;q++){
        if(arr[q]<pivot){
            count++;
        }
    }
    int temp =  arr[si+count];
    arr[si+count]=pivot;
    arr[si]=temp;

    
    while(i<si+count && j > si+count){
        if(arr[i]>pivot){
            if(arr[j]<pivot){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
            else{
                j--;
            }
            
        }
        else{
            i++;
        }
       
       
    }

    return si+count;
}

void quickSort(int arr[],int si, int ei){
    if(si>=ei){
        return;
    }
    int partitionIndex = partition(arr,si,ei);
    quickSort(arr,si,partitionIndex-1);
    quickSort(arr,partitionIndex+1,ei);

}

int main(){
    int arr[] = {35,50,15,25,80,20,90,45};
    quickSort(arr,0,6);
    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
}