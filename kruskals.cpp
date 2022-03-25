#include <iostream>
#include<vector>
#include<set>
using namespace std;

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
       
    }
    
    void Kruskal(){
        int* weights = new int[numberOfEdges];
        int** vertices = new int*[numberOfEdges];
        int ind=0;
        for(int i=0;i<numberOfVertices;i++){
            for(int j=0;j<numberOfVertices;j++){
                if(AdjacencyMatrix[i][j]!=0){
                    weights[ind]=AdjacencyMatrix[i][j];
                    vertices[ind]=new int[2];
                    vertices[ind][0]=i;
                    vertices[ind][1]=j;
                    ind++;
                }
            }
        }


// for(int i=0;i<ind;i++){
//                 cout<<weights[i] << endl;
//                 cout << vertices[i][0] << " " << vertices[i][1] << endl;
//             }


        //sort asc (insertion sort)

            for(int i=1;i<ind;i++){
                int temp=weights[i];
                int* temp1=vertices[i];
                int index=0;
                for(int j=i-1;j>=-1;j--){
                    index=j;
                    if(temp<weights[j]){
                        weights[j+1]=weights[j];
                        int* v1 = vertices[j];
                        // int* v2=vertices[j+1];
                        vertices[j+1]=v1;
                        // vertices[j]=v2;

                    }
                    else{
                        break;
                    }
                    

                }
                weights[index+1]=temp;
                vertices[index+1]=temp1;
            
            }
        

            vector<set<int>> sets;

            for(int i=0;i<numberOfVertices;i++){
                
                set<int> s;
                s.insert(i);
                sets.push_back(s);
            }



            
        
            cout << "Edges in MST are: " << endl;
            
            for(int q=0;q<ind;q++){
                // cout << vertices[q][0] << endl;
                int w=weights[q];
                int s=vertices[q][0];
                int e=vertices[q][1];
                // cout << "Edges in MST are: " << endl;
                //check if this edge is safe or not
                set<int> a;
                set<int> b;
                bool add=true;
                
                for(set<int> s1 : sets){
                    // cout<< "in "  << s1.count(s)<<endl;
                     if(s1.count(s) && s1.count(e)){
                        //  cout << "Edges in MST are: " << endl;
                         add=false;
                         break;
                     }
                     if(s1.count(s)) {
                         for(int ele : s1){
                             a.insert(ele);
                         }
                        //  a =s1;
                     }
                     else if(s1.count(e)){
                         for(int ele : s1){
                             b.insert(ele);
                         }
                     } 
                 }
                 if(add==false){
                     
                    //  cout << "Edges in MST are: " << endl;
                     continue;
                 }
                 //ONLY UNION IS NOT WORKING HERE , C++ 😠
                //  set<int> t;
                 for(set<int> s1 : sets){
                     if(s1==a) {//this detecting that 2 sets equal or not can't be directly, so do sir wala LL method only!

                        // set<int> t;
                        // s1=t;
                        s1.clear();
                     }
                     else if(s1==b){
                        //union
                        //  cout << "Edges in MST are: " << endl;

                        s1.clear();
                        for(int i1:a){
                            s1.insert(i1);
                        }
                        for(int i1:b){
                            s1.insert(i1);
                        }
                        // s1=t;
                     }
                    //  cout << "bla " << s1.count(s) << endl;

                 }
                 //print edges
                cout << s << " " << e << endl;
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
    
    graph.Kruskal();
        
    
    
    
    return 0;
}
