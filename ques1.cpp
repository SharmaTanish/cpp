// ques --> ujjwal went to the market and boought 6 books of price as 10,8,9,25,50,15.
// during coming back to home, vijay met him and both bought another book of
// price 12 . If ujjwal wrote the price in his diary from left to right as per book no. 10,8,9....
// by taking the reference of price of last book . sort the prices of all book in desc order using quick sort

#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei){
    int i = si;
    int j=ei;
    // change pivot ele since taking last ele as ref and also change algo to get in desc order
    
    int pivot = arr[ei];
    int count=0;
    for(int q=si;q<=ei;q++){
        if(arr[q]<pivot){
            count++;
        }
    }
    int temp =  arr[ei-count];
    arr[ei-count]=pivot;
    arr[ei]=temp;

    
    while(i<ei-count && j > ei-count){
        if(arr[i]<pivot){
            if(arr[j]>pivot){
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

    return ei-count;
}

void quickSort(int arr[],int si, int ei){
    if(si>=ei){
        return;
    }
    int partitionIndex = partition(arr,si,ei);
    // as here taking pivot ele from last , therefore it is good habit to do recursive calls from last side only, instead from starting from beginning like we are doing now, we should call like --> quickSort(ei,partitionIndex+1) and then quickSort(partitionIndex-si) , this is just writing convection logic is same!
    quickSort(arr,si,partitionIndex-1);
    quickSort(arr,partitionIndex+1,ei);

}

int main(){
    int size;
    cout << "Enter number of books purchased : "; 
    cin >> size;
    int arr[size];
    cout << "Enter price of all books purchased separated by space : ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    quickSort(arr,0,size-1);
    cout << "Sorted price of all books taking last book as reference in quick sort are : ";
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}
