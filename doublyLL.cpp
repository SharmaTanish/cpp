// IMPLEMENTING DOUBLY LL
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    Node (int data){
        Node::data = data;
        next = NULL;
        prev = NULL;
    }
};

Node* insertInBeginning(Node* &head, int data){

Node* node3 = new Node(data);
    if(head!=NULL){
    head->prev= node3;
    }
    node3->next = head;

    return node3;

}

void print(Node* head){
     while(head!=NULL){
        cout << head -> data << " "; 
        head = head -> next;
    }
       cout << endl;
     
}

Node* deleteFromBeginning(Node* head){
    head = head->next;
    head->prev=NULL;
    return head;
}

Node* deletePrevNode(Node* head, int data){
    Node* temp = head;
    while(head != NULL){
        if(head->data == data){
            break;
        }
        head = head->next;
    }

    if(head == NULL){
        cout << "Elememt not found in LL" << endl;
        return temp;
    }
    if(head->prev == NULL){
        cout << "Previous elememt not there exist of given elememt in LL" << endl;
        return temp;
    }
    head->prev =  head->prev->prev;
    if(head->prev!=NULL){
    head->prev->next = head;
    }
  if(head->prev != NULL){
        head=temp;
    }
    return head;

}

int main(){
    
    Node* head = NULL;
    head = insertInBeginning(head, 5);
    head = insertInBeginning(head, 10);
    head = insertInBeginning(head, 15);
    head = insertInBeginning(head, 20);

   print(head);

   head = deleteFromBeginning(head);

    print(head);

    head = deletePrevNode(head,5);
    print(head);

    return 0;
}