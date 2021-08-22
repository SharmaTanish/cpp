// IMPLEMENTING LINKED LIST

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

Node* insertInBeginning(Node* head, int data){

    // Node* node3 = new Node(data);
    // node3->next = head;
    // head =  node3;
    // return node3;

    cout << head << " Inside func1" << endl;

    Node node3(data);
    node3.next = head;
    head = &node3;
    cout << head << " -----------------Inside" << endl;
    return head;

// &node3 -> next

    // cout << node3.next << " Inside func2"  << endl;
     cout << head << " Inside func3" << endl;
    // cout << head-> next-> data << endl;


}

int main(){
  
    Node node1(5);
    Node* head = &node1;
    cout << &node1 << " " << head << " " << &head << endl;
    cout << head->data << " head data in main";
    Node node2(10);
    node1.next = &node2;     
    Node node5(100);
    node2.next = &node5; 
   
    Node* temp=head;


cout << endl;


   head = insertInBeginning(head , 50);

    // insertInBeginning(head, 1000);
    cout << head << " -----------------outside";

 

cout << endl;

    while(head!=NULL){
        cout << head->data << " "; // IN PLACE OF " " IF WRITE ENDL THEN COMING SOME GARBAGE VALUES 😭
        head = head -> next;
     
    }


    return 0;

}