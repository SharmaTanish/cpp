// IMPLEMENTING SINGLY LL
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node (int data){
        Node::data = data;
        next = NULL;
    }
};

Node* insertInBeginning(Node* &head, int data){

Node* node3 = new Node(data);
    node3->next = head;
    return node3;

}

void print(Node* head){
     while(head!=NULL){
        cout << head -> data << " "; 
        head = head -> next;
    }
}

Node* deleteFromBeginning(Node* head){
    head = head->next;
    return head;
}

int main(){
    
    Node* head = NULL;
    head = insertInBeginning(head, 5);
    head = insertInBeginning(head, 10);
    head = insertInBeginning(head, 15);
    head = insertInBeginning(head, 20);

   print(head);
   cout << endl;

   head = deleteFromBeginning(head);

   print(head);

    return 0;
}