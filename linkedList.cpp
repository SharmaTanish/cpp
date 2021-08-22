// IMPLEMENTING LINKED LIST

#include <iostream>
using namespace std;

// struct Node{
//     int data;
//     Node* next;
    
// }

class Node {
    public:
    int data;
    Node* next;
    Node (int data){
        Node::data = data;
        next = NULL;
    }
};

void insertInBeginning(Node* &head, int data){

// Node* node3 = new Node(data);
//     node3->next = head;
//     return node3;



    Node node3(data);
    node3.next = head;
    head = &node3;
    cout << head-> next-> data << endl;


// while(head!=NULL){
//         cout << head -> data << " "; 
//         head = head -> next;
//         // cout << newHead << endl;
//     }
//     cout << "Inside func " << endl ;

    // return head;

// Node* node3 = new Node(data);   // also works
//     node3->next = head;
//     head = node3;
//     return head;


// Node node3 = new Node(data); // with "new" can make only pointer type objects
//     node3.next = head;
//     head = &node3;
//     return head;


    // Node node3(data);
    // node3.next = head;
    // //   cout << head << endl;
    // head = &node3;
    // // cout << head->next << endl;
    // // cout << node3.next << endl;
    // // cout << head << endl;
    // return head;

}

int main(){
  
    Node node1(5);
    Node* head = &node1;
    Node node2(10);
    node1.next = &node2;      
    // cout << head << endl;
    cout << node1.data << endl;
    cout << node2.data << endl;
    cout << node1.next << endl;

    cout << node1.next->data << endl;
    Node* temp=head;
    //  while(head!=NULL){
    //     cout << head -> data << " "; 
    //     head = head -> next;
    //     // cout << newHead << endl;
    // }

cout << endl;
    head = temp;

    cout << endl;

    insertInBeginning(head , 50);
    //  cout << head-> next-> data << " in main";

//  while(head!=NULL){
//         cout << head -> data << " "; 
//         head = head -> next;
//         // cout << newHead << endl;
//     }

cout << endl;

    while(head!=NULL){
        cout << head -> data << " "; // IN PLACE OF " " IF WRITE ENDL THEN COMING SOME GARBAGE VALUES 😭
        head = head -> next;
        // cout << newHead << endl;
    }


    // int a = 5;
    // int* ptr = &a;
    // cout << ptr << endl;
    // int* ptr2=ptr;
    // cout << ptr << " " << ptr2;

    return 0;

}