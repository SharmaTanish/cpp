#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include<utility>
#include<limits.h>
#include <unordered_set>
using namespace std;

// class Edge{
//     public:
//         int s;
//         int e;
//         int w;
// };
// class Comp {
//     public:
//      bool operator()(pair<int,int> a, pair<int,int> b) //by deafult in ascending on basis of first
        
//     {
//         return a.second > b.second;
//     }
// };

class Graph
{
    private:
    int numberOfVertices;
    int **AdjacencyMatrix;


    public:
    Graph(int noVertices)
    {
        this->numberOfVertices=noVertices;
        
        AdjacencyMatrix=new int*[numberOfVertices];
        for (int i=0;i<=noVertices-1;i++)
        {
            AdjacencyMatrix[i]=new int[numberOfVertices];
            for (int j=0;j<=noVertices-1;j++)
            {
                AdjacencyMatrix[i][j]=0;    
            }
			           
        }
      
    }
   
    void AddEdge(int i, int j, int weight)
    {
        AdjacencyMatrix[i][j]=weight;
        // AdjacencyMatrix[j][i]=weight;//undirected
       
    }
    
    void bellmen(int s){
        int** dp = new int*[numberOfVertices];
        for(int i=0;i<numberOfVertices;i++){
            dp[i]=new int[numberOfVertices];
        }
        dp[0][s]=0;
        for(int i=0;i<numberOfVertices;i++){
            if(i==s) continue;
            dp[0][i]=INT_MAX;
        }
        vector<pair<int,int>> edges;
        for(int i=0;i<numberOfVertices;i++){
            for(int j=0;j<numberOfVertices;j++){
                if(AdjacencyMatrix[i][j]!=0){
                    pair<int,int> p;
                    p.first=i;
                    p.second=j;
                    edges.push_back(p);
                }
            }
        } 

        int n=1;
        while(n<numberOfVertices){
            
            for(int i=0;i<numberOfVertices;i++){
                    dp[n][i]=dp[n-1][i];
            }

            for(int i=0;i<edges.size();i++){
                pair<int,int> p=edges[i];
                
                if(dp[n-1][p.first]!=INT_MAX && dp[n-1][p.second]>dp[n-1][p.first]+AdjacencyMatrix[p.first][p.second]){
                    dp[n][p.second]=dp[n-1][p.first]+AdjacencyMatrix[p.first][p.second];
                }
                // else {
                //     dp[n][p.second]=dp[n-1][p.second];
                // }
            }

            n++;
        }
        for(int i=0;i<numberOfVertices;i++){
            cout << dp[numberOfVertices-1][i] << endl;
        }
    }
      
    

};


int main()
{
 
    // int n;
    // cout << "Enter total number of vertices: ";
    // cin >> n;
    // // cout << "Enter total number of Edges: ";
    // // cin >> m;

    // Graph graph(n);

    // cout << "Do you want to add edges to in between vertices of the graph(yes/no): " ;
    // string str;
    // cin >> str;
    // // str=tolower(str);
    // while(str=="yes"){
    //     cout << "Enter 2 vertices in between you want to add a direct edge: ";
    //     int a,b,w;
    //     cin >> a >> b;
    //     cout << "Enter weight : ";
    //     cin >> w;
        
    //     graph.AddEdge(a,b,w);
    //     cout << "Do you want to add more edges in the graph(yes/no): " ;
        
    //     cin >> str;
    // }


    Graph graph(5);
    graph.AddEdge(1,2,5);
    graph.AddEdge(1,3,8);
    graph.AddEdge(1,4,-4);
    graph.AddEdge(2,1,-2);
    graph.AddEdge(3,2,-3);
	graph.AddEdge(3,4,9);
    graph.AddEdge(4,2,7);
    graph.AddEdge(4,0,2);
    graph.AddEdge(0,1,6);
    graph.AddEdge(0,3,7);
  

    
    int s;
    s=0;
    // cout << "Source : " ;
    // cin >> s;
    // cout << "Destination : ";
    // cin >> e;
    graph.bellmen(s);
        
    
    
    
    return 0;
}
