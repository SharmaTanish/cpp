#include<iostream>
#include<utility>
using namespace std;

pair<int,int> helper(int arr[],int s,int e){
    if(s==e){
        pair<int,int> p;
        p.first=arr[s];
        p.second=arr[e];
        return p;
    }
    if(s==e-1){
        pair<int,int> p;
        if(arr[s]<arr[e]){
            p.first=arr[s];
        }
        else{
            p.first=arr[e];
        }
        if(arr[s]<arr[e]){
            p.second=arr[e];
        }
        else{
            p.second=arr[s];
        }
        
        return p;
    }
    int mid=(s+e)/2;
    pair<int,int> p1 = helper(arr,s,mid);
    pair<int,int> p2 = helper(arr,mid+1,e);
    pair<int,int> p;
    if(p1.first<p2.first){
        p.first=p1.first;
    }
    else{
        p.first=p2.first;
    }
    if(p1.second<p2.second){
        p.second=p2.second;
    }
    else{
        p.second=p1.second;
    }
    return p;
}

int main(){
    int arr[] = {4,9,0,799,541,7,8,2,8,1,785};
    pair<int,int> p = helper(arr,0,10);
    cout << "min " << p.first << endl;
    
    cout << "max " << p.second << endl;
}