//implementation disjoint set using tree notation with any hueristic
#include <iostream>

using namespace std;

struct node
{
	int key;
	node *parent;
};

void makeset(node *x, int k)
{
	x->parent=x;
	x->key=k;
}

node* findset(node *x)
{
	if (x!=x->parent)
		return findset(x->parent);
	else
		return x->parent;	
}

void unionset(node *x,node *y)
{
	node *t1=findset(x);
	node *t2=findset(y);
	t2->parent=t1;
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
