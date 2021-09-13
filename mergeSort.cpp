// merge sort
// incomplete
#include <iostream>
using namespace std;


void merge(int arr[],int si,int ei){
    int left = si;
    int mid = (si+ei)/2;
    int right = mid+1;
    int* temp = new int[ei-si+1];
    int index=0;
    while(left<=mid && right <= ei ){
        if(arr[left]<arr[right]){
            temp[index]=arr[left];
            index++;
            left++;
        }
        else{
            temp[index]=arr[right];
            index++;
            right++;
        }
    }
    while(left<=mid){
        temp[index]=arr[left];
        index++;
        left++;
    }
    while(right<=ei){
        temp[index]=arr[right];
        index++;
        right++;
    }

    for(int q=0;q<ei-si+1;q++){
        arr[si+q]=temp[q];
    }
}


void mergeSort(int arr[],int si, int ei){
    if(si>=ei){
        return;
    }
    int mid=(si+ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,ei);
}

int main(){
    int arr[] = {8,218,6,8,1,2};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout << arr[i] << " ";
    }

}