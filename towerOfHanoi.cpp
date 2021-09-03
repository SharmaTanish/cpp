// Tower of Hanoi

// METHOD 1 --> CREATE A LINKED LIST CLASS AND IT ONE OBJECT WILL BE LINKED LIST ( IN JAVA MOSTLY USE THIS METHOD ONLY )
// #include <iostream>
// using namespace std;

// class Node {
//     public:
//     int data;
//     Node* next;
//     Node (int data){
//         Node::data = data;
//         next = NULL;
//     }
// };

// class LinkedList{

//     public:


//     Node* top;
//     int size=0;

//     int push( int data){
//         if(top==NULL){
//             Node* newNode = new Node(data);
//             // cout << data << " node is inserted in stack" << endl;
//             top=newNode;
//             size++;
//             return data;
//         }
//         Node* newNode = new Node(data);
//         // cout << data << " node is inserted in stack" << endl;
//         newNode->next = top;
//         top = newNode;
//         size++;
//         return data;

//     }

//     int size(){
//         return size;
//     }

//     bool isEmpty(){
//         return size==0;
//     }

//     int pop(){
//         int temp= top->data;
//         top=top->next;
//         size--;
//         return temp;
//     }

//     void print(){
//         Node* temp=top;
//         while(top!=NULL){
//             cout << top->data << " ";
//             top=top->next;
//         }
//         top=temp;
//         cout << endl;
//     }
// };


/////////////////////////////////////////////////////////////////////

// METHOD --> HAVE JUST LINKED LIST FUNCTIONS AND IN MAIN CREATE HEAD OF LINKED LIST, EACH HEAD WILL BE LIKE 1 LINKED LIST AND PASS THIS EAD TO THESE FUCTION EACH TIME IN ORDER TO UPADTE THAT HEAD WALE LINKED LIST

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

// class Triplet{
//     public:

//     Node* headA;
//     Node* headB;
//     Node* headC;
// };


    // int size=0; // IN THIS METHOD CAN'T HAVE SIZE FUNCTION!!!


    Node* push( Node* top, int data){
        if(top==NULL){
            Node* newNode = new Node(data);
            // cout << data << " node is inserted in stack" << endl;
            top=newNode;
            return top;
        }
        Node* newNode = new Node(data);
        // cout << data << " node is inserted in stack" << endl;
        newNode->next = top;
        top = newNode;
        return top;

    }


    Node* pop(Node* top){
        if(top!=NULL){
        top=top->next;
        }
        return top;
    }

    void print(Node* top){
        Node* temp=top;
        while(top!=NULL){
            cout << top->data << " ";
            top=top->next;
        }
        top=temp;
        cout << endl;
    }


void towerOfHanoi(int n ,Node* &headA,Node* &headB,Node* &headC){  // '&' dena zarurir hai to reflect canges in main
    if(n<=1){  // base case
        headA = pop(headA);
        headC = push(headC,5);
        return;
        // Triplet* obj = new Triplet;
        // obj->headA=headA;
        // obj->headB=headB;
        // obj->headC=headC;
        // return obj;
    }


    
    // headC = pop(obj->headC);
    // headA=push(obj->headA,5);
    // headC=pop(obj->headC);
    // headB=push(obj->headB,5);
    // headA = pop(obj->headA);
    // headB = push(obj->headB,5);
    // headA  = pop(obj->headA);
    // headC  = push(obj->headC,5);
    // headB  = pop(obj->headB);
    // headA = push(obj->headA,5);
    // headB = pop(obj->headB);
    // headC = push(obj->headC,5);
    // headA = pop(obj->headA);
    // headC = push(obj->headC,5);
    towerOfHanoi(n-1,headA,headB,headC);  

    cout << headA << "----------A----------"<< endl;
     cout << headB << "----------B----------"<< endl;
      cout << headC << "----------C----------"<< endl;

    headC = pop(headC);
    headA=push(headA,5);
    headC=pop(headC);
    headB=push(headB,5);
    headA = pop(headA);
    headB = push(headB,5);
    headA  = pop(headA);
    headC  = push(headC,5);
    headB  = pop(headB);
    headA = push(headA,5);
    headB = pop(headB);
    headC = push(headC,5);
    headA = pop(headA);
    headC = push(headC,5);

    // obj->headA=headA;
    // obj->headB=headB;
    // obj->headC=headC;
    // return obj;
}



int main(){
    
    Node* headA=NULL;
    Node* headB=NULL;
    Node* headC=NULL;


    // C = output LL, A = input LL, B = which just used to do required task
    int n=3;
    // cin >> n;
    for(int i=0;i<n;i++){
        // int ele;
        // cin >> ele;
        headA = push(headA,5);

    }
    print(headA);
    cout << headA << "+++++++++++++++++++++++"<< endl;
    towerOfHanoi(n,headA,headB,headC);
    cout << headA << "+++++++++++++++++++++++" << endl;
    cout << "A--> ";
    print(headA);
    cout << "B--> ";
    print(headB);
    cout << "C--> ";
    print(headC);

}