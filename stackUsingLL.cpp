// STACK USING LINKED LIST

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

Node* top;

Node* insertInStack( int data){
    if(top==NULL){
        Node* newNode = new Node(data);
        cout << data << " node is inserted in stack" << endl;
        top=newNode;
        return top;
    }
    Node* newNode = new Node(data);
    cout << data << " node is inserted in stack" << endl;
    newNode->next = top;
    top = newNode;
    return top;

}

void print(){
    Node* temp=top;
    while(top!=NULL){
        cout << top->data << " ";
        top=top->next;
    }
    top=temp;
    cout << endl;
}

int main(){
    top = insertInStack(10);
    top = insertInStack(80);
    top = insertInStack(90);
    top = insertInStack(520);

    print();

    return 0 ;

}

























// Node* popFromStack(){
//     if(top==NULL){
//         return NULL;
//     }
//     cout << top -> data << " is removed from stack" << endl;
//     top=top->next;
 
//     return top;
    
// }

















// int getPairsCount(int arr[], int n, int sum){
//   // Write your code here
//   int i=0;
//   int j=n-1;
//   int count =0;
//   while(i<j){
// 	if(arr[i]+arr[j]==sum){
// 	  count++;
//       int q=1;
//       while((arr[j]==arr[j-q] || arr[i]==arr[i+q]) && q<n-1){
//         count++;
//         q++;
//       }
//       j--;
//       i++;
//     }
//     else if(arr[i]+arr[j]>sum){
// 	  j--;
//     }
//     else if(arr[i]+arr[j]<sum){
//       i++;
//     }
//   }
  
//   return count;
  
// }