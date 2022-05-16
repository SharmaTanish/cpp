#include <iostream>
using namespace std;

bool func(int arr[],int n,int target,int ind){
    if(target==0){
        return true;
    }
    if(target<0){
        return false;//backtrack
    }
    if(ind>=n){
        return false;
    }
    //pick
    bool ans1 = func(arr,n,target-arr[ind],ind+1);
    //not pick
    bool ans2 = func(arr,n,target,ind+1);
    return ans1 || ans2;
}

// bool funcdp(int arr[], int n, int target, int ind, )


int main(){
    int arr[] = {5,7,8,9,4};
    int target=19;//7 8 4

    //using recursion (backtracking)

    cout << func(arr,5,target,0) << endl;
    
}