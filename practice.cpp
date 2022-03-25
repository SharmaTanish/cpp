#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;	
};
class LinkedList
{


  public:
    node *head, *tail;
  LinkedList()
  {
    head=NULL;
    tail=NULL;
  }
  void createnode(int value)
  {
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
      head=temp;
      tail=temp;
      temp=NULL;
    }
    else
    {	
      tail->next=temp;
      tail=temp;
    }
  }
  void display()
  {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  }
};

node* mergeLists(node* head1, node* head2)
{
  node* newHead=new node();
  newHead=NULL;
  node* tail = new node();
  tail=NULL;
//   head1=head1->head;
//   head2=head2->head;
  while(head1!=NULL && head2!=NULL){
     node* Node= new node();
     
    if(head1->data >= head2->data){
     
     
      Node->data=head2->data;
      Node->next=NULL;
          head2=head2->next;
      
    }
    else{
      
      Node->data=head1->data;
      Node->next=NULL;
       head1=head1->next;
    }
    
     if(newHead==NULL){
        newHead=Node;
        
        tail=newHead;
      }
      tail->next=Node;
      tail=Node;
      
  

  }
  
  while(head1!=NULL){
    node* Node= new node();
     Node->data=head1->data;
      Node->next=NULL;
    head1=head1->next;
      tail->next=Node;
      tail=Node; 
  }
  while(head2!=NULL){
    node* Node= new node();
     Node->data=head2->data;
      Node->next=NULL;
    head1=head1->next;
    
       tail->next=Node;
      tail=Node;
  }
  return newHead;
//   LinkedList* obj = new LinkedList;
//   obj->head=newHead;
//   obj->tail=tail;
//   return obj;
}

int main(){

    int t,n,m,k;
  LinkedList head1, head2, t1, t2;
  cin>>n;
  while(n>0)
  {
    cin>>k;
    head1.createnode(k);
    n--;
  }
  cin>>m;
  while(m>0)
  {
    cin>>k;
    head2.createnode(k);
    m--;
  }
  node* h1= new node();
  h1=head1.head;
  node* h2= new node();
  h2=head2.head;
  node* abc = mergeLists(h1, h2);
  while(abc!=NULL){

      cout << abc->data ;
      abc=abc->next;
  }
//   t1.display();
  cout<<endl;
  return 0;
}