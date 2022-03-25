#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
double maximize_profit(int n, double w, double wvarray[10][2])
{
            // Write your code here
    pair<double,pair<double,double>>* arr = new pair<double,pair<double,double>>[n];
    for(int i=0;i<n;i++){
        double w1 = wvarray[i][0];
        double v = wvarray[i][1];
        // arr[i]=v/w1;
        pair<double,pair<double,double>> p;
        p.first=v/w1;
        pair<double,double> p1;
        p1.first=w1;
        p1.second=v;
        p.second=p1;
        arr[i]=p;
    }
    sort(arr,arr+n);//
    double weight=0;
    double profit=0;
    // for(int i=0;i<n;i++){
    //     cout << arr[i].first << " " << arr[i].second.first << endl;
    // }
    for(int i=n-1;i>=0;i--){
        if(weight+arr[i].second.first<=w){
            weight+=arr[i].second.first;
            profit+=arr[i].second.second;
            // cout << arr[i].second.first << " " << arr[i].second.second << endl;
        }
        else{
            // cout << arr[i].second.first << " " << arr[i].second.second << endl;
           
            profit+=(w-weight)*arr[i].second.second/arr[i].second.first;
            break;
        }
    }
    return profit;
    
}
int main()
{
    double wvarray[10][2],w, max_value;            // wvarray[10][2] is the array consisting of profit and weight values for all the Items where profit and weight is stored in the first and second column respectively; 
                                                                                                                                                                //  w : Maximum weight thief can carry into his bag
                                                                                                                                                           // max_value : Maximum profit earned
   int n; 
   cin>>n;   // Total number of Items
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<2;j++)
	{
                 cin>>wvarray[i][j];    // Items are entered in a sorted manner according to value/weight or (wvarray[i][1]/wvarray[i][0])
	}
    }
   cin>>w;   // Maximum weight thief can carry into his bag
   max_value = maximize_profit(n,w,wvarray);
   cout<<max_value;
}

