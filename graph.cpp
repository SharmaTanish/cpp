#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    private:
        int vertices;
        int** adjagecyMatrix;
        char type;
    public:
        Graph(int vert,char type){
            this->vertices=vert;
            this->type=type;
            adjagecyMatrix = new int*[vert];
            for(int i=0;i<vertices;i++){
                adjagecyMatrix[i] = new int[vertices];
            }
            for(int i=0;i<vertices;i++){
                for(int j=0;j<vertices;j++){
                    adjagecyMatrix[i][j]=0;
                }
            }
        }

        void addEdge(int a,int b){
            if(type=='u'){
                adjagecyMatrix[a][b]=1;
                adjagecyMatrix[b][a]=1;
            }
            else{
                adjagecyMatrix[a][b]=1;
            }
        }

        void edgesPrint(){
            for(int i=0;i<vertices;i++){
                for(int j=0;j<vertices;j++){
                    if(adjagecyMatrix[i][j]==1){
                        cout << i << " " << j << endl;
                    }
                }
            }
        } 

        void bfs(int startVertex){
            queue<int> q;
            // int visited[vertices];
            //can do like:-
            int* visited = new int[vertices];
            for(int i=0;i<vertices;i++){
                visited[i]=0;
            }

            q.push(startVertex);
            cout << startVertex << " ";
            visited[startVertex]=1;
            
            while(q.size()>0){
                int ele = q.front();
                q.pop();
                
                for(int i=0;i<vertices;i++){
                    if(adjagecyMatrix[ele][i]==1 && visited[i]!=1){
                        q.push(i);
                        cout << i << " ";
                        visited[i]=1;
                    }
                }
            }

        }

        void dfsHelper(int startVertex,int* vis){
            cout << startVertex << " ";
            vis[startVertex]=1;
            for(int i=0;i<vertices;i++){
                if(adjagecyMatrix[startVertex][i]==1 && vis[i]!=1){
                    dfsHelper(i,vis);
                }
            }
            
        }

        void dfs(int startVertex){
            int* vis=new int[vertices];
            for(int i=0;i<vertices;i++){
                vis[i]=0;
            }
            dfsHelper(startVertex,vis);
            
        }

        void topoSortHelper(int startVertex, int*& vis, stack<int>& stk){
            // cout << startVertex << " ";
            vis[startVertex]=1;
            for(int i=0;i<vertices;i++){
                if(adjagecyMatrix[startVertex][i]==1 && vis[i]!=1){
                    topoSortHelper(i,vis,stk);
                }
                // stk.push(startVertex);
                
            }
            stk.push(startVertex);
        }

        void topoSort(){
            int* vis=new int[vertices];
            for(int i=0;i<vertices;i++){
                vis[i]=0;
            }
            stack<int> stk;
            for(int i=0;i<vertices;i++){
                if(vis[i]!=1)
                topoSortHelper(i,vis,stk);
            }
            while(stk.size()!=0){
                int temp=stk.top();
                stk.pop();
                cout << temp << " ";
            }
        }

        
        ~Graph(){
            for(int i=0;i<vertices;i++){
                free(adjagecyMatrix[i]);
            } 
            free(adjagecyMatrix);
        }

};

int main(){
    //directed and undirected graph also ask from user
    int n;
    char type;
    cout << "Enter total number of vertices: ";
    cin >> n;
    cout << "Enter 'd' for directed graph or 'u' for undirected graph: ";
    cin >> type;
    Graph graph(n,type);

    cout << "Do you want to add edges to in between vertices of the graph(yes/no): " ;
    string str;
    cin >> str;
    // str=tolower(str);
    while(str=="yes"){
        cout << "Enter 2 vertices in between you want to add a direct edge: ";
        int a,b;
        cin >> a >> b;
        graph.addEdge(a,b);
        cout << "Do you want to add more edges in the graph(yes/no): " ;
        
        cin >> str;
    }
    cout << "Edges in your graph are in between following vertices: " << endl;

    graph.edgesPrint();

    cout << "Enter starting vertex for BFS/DFS traversal: " << endl;
    int startVertex;
    cin >> startVertex;
    cout << "BFS traversal of the graph starting from " << startVertex << " is: " << endl;

    graph.bfs(startVertex);

    cout << "\n";
    cout << "DFS traversal of the graph starting from " << startVertex << " is: " << endl;

    graph.dfs(startVertex);
    cout << "\n";


    /////////////////////////////////////////////////////

    //topological sort
    cout << "Topological Sorted order of the graph is: " << endl;
    graph.topoSort();


    return 0;

}