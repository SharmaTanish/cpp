#include <iostream>
#include <string>
#include<algorithm> // for sort
using namespace std;

class Act{
    public:
    int s;
    int e;
    string name;
};


bool comp(Act a, Act b){
    if(a.e>b.e) return false; //opposite from java, also function not class
}


int main(){
    int n;
    cout << "Enter number of total activities scheduled : ";
    cin >> n;
    int* start_time = new int[n];

    int* end_time = new int[n];
    
    string* act_name = new string[n];

    // cout << "Please enter activities in ascending order of finishing time!!" << endl;

    for(int i=1;i<=n;i++){
        cout << "Enter activity " << i << " name : ";
        cin >> act_name[i-1];

        cout << "Enter activity " << i << " starting time and finishing time : ";
        cin >> start_time[i-1];
        cin >> end_time[i-1];
         
    }

    // if input not sorted

    Act* arr = new Act[n];

    for(int i=0;i<n;i++){
        Act a;
        a.s=start_time[i];
        
        a.e=end_time[i];
        
        a.name=act_name[i];
        arr[i]=a;
    }

    
    sort(arr,arr+n,comp);

    cout << "Maximum activities you can attend are : " << endl;

    cout << arr[0].name << " from " << arr[0].s << " to " << arr[0].e << endl;

    int prev_end_time = arr[0].e;;
    for(int i=1;i<n;i++){
        if(arr[i].s>=prev_end_time){
            cout << arr[i].name << " from " << arr[i].s << " to " << arr[i].e << endl;
            prev_end_time = arr[i].e;
        }
    }
    




    // //start from 0th activity, assuming n>0 and input is sorted
    // cout << act_name[0] << " from " << start_time[0] << " to " << end_time[0] << endl;

    // int prev_end_time = end_time[0];
    // for(int i=1;i<n;i++){
    //     if(start_time[i]>=prev_end_time){
    //         cout << act_name[i] << " from " << start_time[i] << " to " << end_time[i] << endl;
    //         prev_end_time = end_time[i];
    //     }
    // }
    
}