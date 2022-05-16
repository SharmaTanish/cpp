//implementation disjoint set using tree notation with both "UNION BY RANK" AND "PATH COMPRESSION" heuristics.
#include <iostream>
#include <stack>
using namespace std;

struct node
{
	int key;
	node *parent;
    int rank;
};

void makeset(node *x, int k)
{
	x->parent=x;
	x->key=k;
    x->rank=1;
}

stack<node*> stk;
node* findset(node *x)
{

	if (x!=x->parent){
        stk.push(x);
		return findset(x->parent);
    }
	else{
        while(stk.size()>0){
            node* temp =stk.top();
            stk.pop();
            temp->parent=x;
            x->rank--;
        }
		return x->parent;	
    }
}

void unionset(node *x,node *y)
{
	node *t1=findset(x);
	node *t2=findset(y);
    if(t1==t2){
        return;
    }
    if(t1->rank>t2->rank){
        t2->parent=t1;
        
    }
    else{
        t1->parent=t2;
        if(t1->rank==t2->rank){
            t2->rank++;
        }
    }
	
}

void print(node *x)
{
	node *root;
	if (x!=x->parent)
		root= findset(x->parent);
	else
		root=x->parent;
	cout<<root->key<<"\n";	
}

int main()
{
	struct node elements[5];
	
	
	makeset(&elements[0],1);
	makeset(&elements[1],4);
	makeset(&elements[2],5);
	makeset(&elements[3],9);
	makeset(&elements[4],11);
	
	for (int i=0;i<=4;i++)
	{
		cout<<"Element Key: "<<elements[i].key<<" Parent Key: "<<elements[i].parent->key<<" Root Key: ";
		print(&elements[i]);
	}
	
	cout<<"\n";
	
	unionset(&elements[0],&elements[1]);
	
	for (int i=0;i<=4;i++)
	{
		cout<<"Element Key: "<<elements[i].key<<" Parent Key: "<<elements[i].parent->key<<" Root Key: ";
		print(&elements[i]);
	}
		
	unionset(&elements[1],&elements[4]);
	
	cout<<"\n";
	
	for (int i=0;i<=4;i++)
	{
		cout<<"Element Key: "<<elements[i].key<<" Parent Key: "<<elements[i].parent->key<<" Root Key: ";
		print(&elements[i]);
	}
	
	unionset(&elements[3],&elements[4]);
	
	cout<<"\n";
	
	for (int i=0;i<=4;i++)
	{
		cout<<"Element Key: "<<elements[i].key<<" Parent Key: "<<elements[i].parent->key<<" Root Key: ";
		print(&elements[i]);
	}
		
	
}
