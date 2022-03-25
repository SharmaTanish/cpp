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
        AdjacencyMatrix[j][i]=weight;//undirected
       
    }
    
    void dijkstra(int s,int e){
        // int s=0;
        // int e=0;
        // int min_edge=INT_MAX;
        // unordered_set<int> set;
       

        // int* parent=new int[numberOfVertices];
        int* key=new int[numberOfVertices];
        for(int i=0;i<numberOfVertices;i++){
            key[i]=INT_MAX;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;//unvisited vertices,min dist till now of this vertex [working like unvisited array]

        pair<int,int> p1;
        p1.first=s; //first --> vertex
        p1.second=0; //second --> key
        key[s]=0;
        pq.push(p1);

        for(int i=1;i<numberOfVertices;i++){
            pair<int,int> p;
            p.first=i;
            p.second=INT_MAX;
            pq.push(p);
        }     

        bool flag=false;
        while(pq.size()>0){//this condition not works as here there after all vertices finalized still pq will contain previous no use elements, so this condition fails, here we need to maintain a count and when count become equal to number of vertices then we will stop!!
            pair<int,int> p =pq.top();
            pq.pop(); //vertex got finalized
            if(p.first==e){
                cout << "Shortest distance from " << s << " to " << e << " : " << endl;
                cout << p.second << endl;
                flag = true;
                break;
            }

            for(int i=0;i<numberOfVertices;i++){
                if(AdjacencyMatrix[p.first][i]!=0){
                    //update keys
                    if(key[i]>AdjacencyMatrix[p.first][i]+key[p.first]){
                        key[i]=AdjacencyMatrix[p.first][i]+key[p.first];
                        pair<int,int> p2;
                        p2.first=i;
                        p2.second=key[i];
                        pq.push(p2); //as we are decreasing edges so it will get more priority hence this worked as others remain in pq at bottom that doesn't matters.
                    }
                }
            }


        }  

        if(!flag)
        cout << "No distance from " << s << " to " << e << "exits!" << endl;
                

    }
      
    

};


int main()
{
 
    int n;
    cout << "Enter total number of vertices: ";
    cin >> n;
    // cout << "Enter total number of Edges: ";
    // cin >> m;

    Graph graph(n);

    cout << "Do you want to add edges to in between vertices of the graph(yes/no): " ;
    string str;
    cin >> str;
    // str=tolower(str);
    while(str=="yes"){
        cout << "Enter 2 vertices in between you want to add a direct edge: ";
        int a,b,w;
        cin >> a >> b;
        cout << "Enter weight : ";
        cin >> w;
        
        graph.AddEdge(a,b,w);
        cout << "Do you want to add more edges in the graph(yes/no): " ;
        
        cin >> str;
    }


    // Graph graph(5);
    // graph.AddEdge(0,1,2);
    // graph.AddEdge(0,3,8);
    // graph.AddEdge(1,2,19);
    // graph.AddEdge(1,4,25);
    // graph.AddEdge(2,4,17);
	// graph.AddEdge(3,4,21);

    
    int s,e;
    cout << "Source : " ;
    cin >> s;
    cout << "Destination : ";
    cin >> e;
    graph.dijkstra(s,e);
        
    
    
    
    return 0;
}
