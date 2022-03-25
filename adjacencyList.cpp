





/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Graph
{
    private:
    
    int NumberOfVertices;
    struct node
    {
        int Vertex;
        int Weight;
        node *next;
    };
    
    struct node** AdjacencyList;
    
    
    public:
    
    Graph(int NoOfVertices)
    {
      	this->NumberOfVertices=NoOfVertices;
        
		//Creating an Array of Pointers of node type and stroring the address
		//of Array in AdjacencyList
		
		AdjacencyList= new node*[NoOfVertices];
        
        //Initializing All Pointers in the Array of Pointers to NULL
        for (int i=0;i<=NoOfVertices-1;i++)
        {
        	AdjacencyList[i]=NULL;
		}
    }
    
        
    void AddEdge(int SV, int EV, int wt)
    {
        
		//Memory Allocated to a New Node and Initialized it
		struct node *s1=new node();
        s1->Vertex=EV;
        s1->Weight=wt;
        s1->next=NULL;
        
        
        struct node *start;
        
        start=AdjacencyList[SV];
        if (start==NULL)   //If No node has been created before in the Adjacency List
        				   //of SV, store the address of Newly Created Node in the
						   //Array of Pointers at suitable index 	
        {
        	AdjacencyList[SV]=s1;
     	}
        else
        {
        //Loop through the nodes of Adjacency List of SV till start does not point
		//to last node in the list 
		   while(start->next!=NULL)
	        {
	            start=start->next;
	        }
	    //Add newly created node in the Adjacency List of SV
			start->next=s1;
		}
        
    }
    
   
    void PrintEdgeList(int SV)
	{
		struct node *start;
		
		start=AdjacencyList[SV];
		if (start==NULL)
		{
			cout<<"\nNo Outgoing Edge Exists from Vertex: "<<SV;
		}
		else
		{
			while (start!=NULL)
			{
				cout<<"\nStart Vertex: "<<SV<<", End Vertex: "<<start->Vertex<<", Weight: "<<start->Weight;
				start=start->next;
			}
		}
		
	}    
	
};


int main()
{
    Graph G1(4);
    
    G1.AddEdge(0,1,23);
    G1.AddEdge(0,2,45);
    G1.AddEdge(1,3,56);
    G1.AddEdge(1,2,78);
    G1.AddEdge(2,3,67);
    G1.AddEdge(3,0,20);
    
    G1.PrintEdgeList(0);
    G1.PrintEdgeList(1);
    G1.PrintEdgeList(2);
    G1.PrintEdgeList(3);
    
    
	return 0;
}











//////////////////////////////////////////////////////////////















/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Graph
{
    private:
    
    int NumberOfVertices;
    struct node
    {
        int Vertex;
        int Weight;
        node *next;
    };
    
    struct node** AdjacencyList;
    
    
    public:
    
    Graph(int NoOfVertices)
    {
      	this->NumberOfVertices=NoOfVertices;
        AdjacencyList= new node*[NoOfVertices];
        
        for (int i=0;i<=NoOfVertices-1;i++)
        {
        	AdjacencyList[i]=NULL;
		}
    }
    
        
    void AddEdge(int SV, int EV, int wt)
    {
        struct node *s1=new node();
        s1->Vertex=EV;
        s1->Weight=wt;
        s1->next=NULL;
        
        struct node *start;
        
        start=AdjacencyList[SV];
        if (start==NULL)
        {
        	AdjacencyList[SV]=s1;
     	}
        else
        {
		   while(start->next!=NULL)
	        {
	            start=start->next;
	        }
			start->next=s1;
		}
        
    }
    
    void AddEdgesOfGraph()
    {
    	
	
		int AddEdge=1; 	//0 Means False and 1 Means True
    	int StartVertex;
    	int EndVertex;
    	int EdgeWeight;
    	
    	while (AddEdge==1)
		{
			cout<<"Enter Start Vertex of Edge";
			cin>>StartVertex;
			
			cout<<"Enter End Vertex of Edge";
			cin>>EndVertex;
			
			cout<<"Enter Weight of Edge";
			cin>>EdgeWeight;
			
			cout<<"Do You Want to Enter More Edges. Enter 0 for No and 1 for Yes";
			cin>>AddEdge;
			
			this->AddEdge(StartVertex, EndVertex,EdgeWeight);
		}
		    	
	}
    
    void PrintEdgeList(int SV)
	{
		struct node *start;
		
		start=AdjacencyList[SV];
		if (start==NULL)
		{
			cout<<"\nNo Outgoing Edge Exists from Vertex: "<<SV;
		}
		else
		{
			while (start!=NULL)
			{
				cout<<"\nStart Vertex: "<<SV<<", End Vertex: "<<start->Vertex<<", Weight: "<<start->Weight;
				start=start->next;
			}
		}
		
	}    
	
	void PrintGraph()
	{
		
		for (int i=0;i<=NumberOfVertices-1;i++)
		{
			cout<<"\n";
			PrintEdgeList(i);
			
		}
	}
    
    
};


int main()
{
    int VertexCount;
    
	cout<<"Enter Number of Vertices for Graph G1";
    cin>>VertexCount;
    
	Graph G1(VertexCount);
	
	G1.AddEdgesOfGraph();
    G1.PrintGraph();
    
	return 0;
}











////////////////////////////////////////////////////////////////