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
    
    void warshell(){
        int** dist = new int*[numberOfVertices];
        for(int i=1;i<numberOfVertices;i++){
            dist[i]=new int[numberOfVertices];
        }

        int** pred = new int*[numberOfVertices];
        for(int i=1;i<numberOfVertices;i++){
            pred[i]=new int[numberOfVertices];
        }

        for(int i=1;i<numberOfVertices;i++){
            for(int j=1;j<numberOfVertices;j++){
                if(i!=j){
                    if(AdjacencyMatrix[i][j]!=0){
                        dist[i][j]=AdjacencyMatrix[i][j];
                    }
                    else dist[i][j]=INT_MAX;
                }
                else dist[i][j]=0;
                pred[i][j]=-1;
            }
        }



        for(int k=1;k<numberOfVertices;k++){
            for(int i=1;i<numberOfVertices;i++){
                for(int j=1;j<numberOfVertices;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                        pred[i][j]=pred[k][j];
                    }
                }
            }
            // for(int i=1;i<numberOfVertices;i++){
            //     for(int j=1;j<numberOfVertices;j++){
            //         cout << dist[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }


        cout << "Shortest distance from each node to every other node:- "<< endl;
        for(int i=1;i<numberOfVertices;i++){
            for(int j=1;j<numberOfVertices;j++){
                cout << dist[i][j] << " ";
            }
            cout << endl;
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


    Graph graph(6);//0 index not using (since taking nodes 1-5)
    graph.AddEdge(1,2,3);
    graph.AddEdge(1,5,-4);
    graph.AddEdge(1,3,8);
    graph.AddEdge(2,5,7);
    graph.AddEdge(2,4,1);
    graph.AddEdge(3,2,4);
	// graph.AddEdge(3,4,9);
    graph.AddEdge(4,1,2);
    graph.AddEdge(4,3,-5);
    graph.AddEdge(5,4,6);
  

    
    // int s;
    // s=0;
    // cout << "Source : " ;
    // cin >> s;
    // cout << "Destination : ";
    // cin >> e;
    graph.warshell();
        
    
    
    
    return 0;
}
