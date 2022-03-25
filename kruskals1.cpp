
#include <iostream>

using namespace std;

class Graph
{
    private:
    int numberOfVertices;
    int **AdjacencyMatrix;
	int numberOfEdges; //Loop will run till all edges have not been considered
	   
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
    void PrintGraph()
    {
        cout<<"Number of Vertices:"<<numberOfVertices;
   
        for (int i=0;i<=numberOfVertices-1;i++)
        {
            for (int j=0;j<=numberOfVertices-1;j++)
            {
                if (AdjacencyMatrix[i][j]!=0)
                    cout<<"\nStart Vertex: "<<i<<" End Vertex: "<<j<<" weight:"<<AdjacencyMatrix[i][j];
            }
           
        }
    }
    
    void Kruskal()
    {
    	//Structure of a linked list node in linked list Representation
    	//of a Disjoint Set. There are three Elements in the node
    	//Vertex, pointer to next element in the linked list, pointer to
    	//the parent node which itself is a pointer to the start of the linked
    	//list.
		struct setNode
    	{
    		int Vertex;
    		setNode *next;
    		setNode **parentNode;
		};
    	
    	//DisjointSets is a pointer to an array whose elements are pointing
    	//to the elements of type setNode. An array of length n will be created
    	//with index position from 0 to n-1 .Initially Element at index position i
		//will point to set initialized for vertex i
		  
    	setNode **DisjointSets;
    	
    	//VertexNode is a pointer to an array whose elements are pointing
    	//to the elements of type setNode. An array of length n will be created
    	//with index position from 0 to n-1 .Initially Element at index position i
		//will point to set initialized for vertex i
		
		//Following is the purpose of creating VertexNode as separate array
		//from DisjointSets 
		//ith Element of VertexNode will be used to access the setNode element
		//created for vertex i as values of Disjoint sets will be set to NULL
		//while applying Union of two linked lists of setNodes
		
    	setNode **VertexNode;
    	
		int u,v,NoOfEdges;
		
		//Memory allocated for DisjointSets Array
		DisjointSets=new setNode*[numberOfVertices];
		//Memory allocated for VertexNode Array
		VertexNode=new setNode*[numberOfVertices];
		
		//setNodes created corresponding to each and every vertex
		//and pointers stored in corresponding elements of 
		//DisjointSets as well as VertextNode Array
		for (int i=0;i<=numberOfVertices-1;i++)
		{
			
			DisjointSets[i]=new setNode;
			VertexNode[i]=DisjointSets[i];
			
			DisjointSets[i]->Vertex=i;
			DisjointSets[i]->next=NULL;
			DisjointSets[i]->parentNode=&DisjointSets[i];
			
		}
		
		NoOfEdges=0;
		
		//Do while loop till all edges have not been considered
		do 
		{
			
			//Printing Elements of DisjointSets Array
			cout<<"\n\n\n\n Address of First Elements of Different Sets";
			for (int i=0;i<=numberOfVertices-1;i++)
			{ 
				cout<<"\n Set No: "<<i<<":"<<DisjointSets[i];	
			}
			
			cout<<"\nPrinting Elements of Different Sets:";
			for (int i=0;i<=numberOfVertices-1;i++)
			{
				setNode *start;
		
				start=DisjointSets[i];
				if (start==NULL)
				{
					cout<<"\nNo Element in the Set No: "<<i;
				}
				else
				{
					cout<<"\n";
					while (start!=NULL)
					{
						cout<<" Vertex: "<<start->Vertex<<", Parent Node: "<<start->parentNode;
						start=start->next;
					}
				}
			
			}
			
			//Fetching next minimum edge
			int min=999;
			for (int i=0;i<=numberOfVertices-1;i++)
			{
				
				for (int j=0;j<=numberOfVertices-1;j++)
				{
					if ((AdjacencyMatrix[i][j]!=0) && ((AdjacencyMatrix[i][j])<min))
					{
						min=AdjacencyMatrix[i][j];
						u=i;
						v=j;
					}
						
				}
			}
			
			cout<<"\nNext Minimum Edge"<<u<<","<<v;
			NoOfEdges=NoOfEdges+1;
			AdjacencyMatrix[u][v]=999;
			
			cout<<"\n Parent of u:"<<VertexNode[u]->parentNode<<", Parent of v:"<<VertexNode[v]->parentNode;
			
			//If parents of both end vertices are not same
			//Union operation needs to be applied
			if (VertexNode[u]->parentNode!=VertexNode[v]->parentNode)
			{
				struct setNode *start,*start1;
				
				//start points to address of first element of the setNode linked list
				//to whom vertex v belongs
				start=*(VertexNode[v]->parentNode);
				
				//Saving the address of first element of the setNode linked list
				//to whom vertex v belongs
				//in a variable start1 as it will be required later on while
				//applying union of two linked lists
				start1=*(VertexNode[v]->parentNode);
				
				//Null stored as the start address of SetNode chain in the
				//DisjointSets Array to whom vertex v belongs to mark as
				//separate set will no longer exist and will be combined
				//with set Corresponding to vertex u
				
				*(VertexNode[v]->parentNode)=NULL;
        		
        		//Printing all elements of Set before change of parent
        		//and after change of parent 
		       	while(start!=NULL)
		        {
		        	cout<<"\nStart:"<<start<<"Vertex:"<<start->Vertex<<"Parent Node:"<<start->parentNode;
    				start->parentNode=VertexNode[u]->parentNode;
		        	cout<<"\nStart:"<<start<<"Vertex:"<<start->Vertex<<"New Parent Node:"<<start->parentNode;
		        	start=start->next;
		        }
				
			    //Initially start will point to first element of
				//setNode list to whom u belongs
					
        		start=*(VertexNode[u]->parentNode);
        	  	//Apply loop till start does not points to last element
				//of the list 
				while(start->next!=NULL)
		        {
		        	start=start->next;
		        }
				
				//Union of two lists. next of last element from 1st list
				//will point to first element of second list 
				start->next=start1;
				cout<<"\nEdge in Spanning Tree: "<<u<<","<<v;
			}
		
			
		}while(NoOfEdges<numberOfEdges);
		
		
    	
	}
    
    
};


int main()
{
 
    Graph g2(7,11);
    g2.AddEdge(0,1,2);
    g2.AddEdge(0,4,14);
    g2.AddEdge(0,3,8);
    g2.AddEdge(1,2,19);
    g2.AddEdge(1,4,25);
    g2.AddEdge(2,4,17);
    g2.AddEdge(2,5,5);
    g2.AddEdge(2,6,9);
	g2.AddEdge(3,4,21);
	g2.AddEdge(4,5,13);
	g2.AddEdge(5,6,1);
    
    g2.Kruskal();
        
    
    
    
    return 0;
}
