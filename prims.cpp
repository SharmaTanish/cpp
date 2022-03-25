#include <iostream>
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
class Comp {
    public:
     bool operator()(pair<int,int> a, pair<int,int> b) //by deafult in ascending on basis of first
        
    {
        return a.second > b.second;
    }
};

class Graph
{
    private:
    int numberOfVertices;
    int **AdjacencyMatrix;
	int numberOfEdges;

    public:
    Graph(int noVertices,int noEdges)
    {
        this->numberOfVertices=noVertices;
        this->numberOfEdges=noEdges;
        
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
        AdjacencyMatrix[j][i]=weight;//undirected
       
    }
    
    void prims(){
        int s=0;
        int e=0;
        int min_edge=INT_MAX;
        unordered_set<int> set;
        //min edge to start with
        for(int i=0;i<numberOfVertices;i++){
            for(int j=0;j<numberOfVertices;j++){
                if(AdjacencyMatrix[i][j]!=0 && AdjacencyMatrix[i][j]<min_edge){
                    min_edge=AdjacencyMatrix[i][j];
                    s=i;
                    e=j;
                }
            }
        }

        int* parent=new int[numberOfVertices];
        int* key=new int[numberOfVertices];
        for(int i=0;i<numberOfVertices;i++){
            key[i]=INT_MAX;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;//vertex,connected weight
        pair<int,int> p;
        p.first=s;
        p.second=0;//no matter
        pq.push(p);
        key[s]=0;
        parent[s]=-1;
        while(pq.size()>0){
            pair<int,int> p1 = pq.top();
            pq.pop();
            // cout <<"vertex " <<  p1.first << " edge " << p1.second <<endl;
            //neighbours
            for(int i=0;i<numberOfVertices;i++){
                
                if(AdjacencyMatrix[p1.first][i]!=0){
                    // cout << AdjacencyMatrix[p1.first][i] <<endl;
                    if(!(set.find(i)==set.end())) continue;
                    if(key[i]>AdjacencyMatrix[p1.first][i]){//equal walo ko update nahi to avoid visited again
                        key[i]=AdjacencyMatrix[p1.first][i];
                        parent[i]=p1.first;
                        pair<int,int> p2;
                        p2.first=i;
                        p2.second=AdjacencyMatrix[p1.first][i];
                        pq.push(p2);
                    }

                }
            }
            set.insert(p1.first);

        }

        cout << "Edges in MST are:" << endl;
        for(int i=0;i<numberOfVertices;i++){
            if(parent[i]==-1) continue;
            cout << i << " " << parent[i] << endl;
        }
            
        }


    

};


int main()
{
 
    Graph graph(7,11);
    graph.AddEdge(0,1,2);
    graph.AddEdge(0,4,14);
    graph.AddEdge(0,3,8);
    graph.AddEdge(1,2,19);
    graph.AddEdge(1,4,25);
    graph.AddEdge(2,4,17);
    graph.AddEdge(2,5,5);
    graph.AddEdge(2,6,9);
	graph.AddEdge(3,4,21);
	graph.AddEdge(4,5,13);
	graph.AddEdge(5,6,1);
    
    graph.prims();
        
    
    
    
    return 0;
}
