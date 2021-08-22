#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

// class Circuit
// {
//   node *head=NULL;
//   node *tail = NULL;
//   int stNodeVal;
//   public:
//   	void createlist()
//     {
      
//       int n;
//       cin>>n;
//       while(n != -1){
//         node *temp = new node();
//         temp->data = n;
//         temp->next=NULL;
//         if(head == NULL)
//         {
//           head=temp;
//           tail=temp;
//         }
//         else{
//           tail->next = temp;
//           tail = temp;
//         }
        
//         cin>>n;
//       }
//       cin>>stNodeVal;
//     }
  
//   void makeTheCircuit()
//   {
//     bool flag = false;
//     node *curr = head;
//     node *st = NULL;
//     cout<<stNodeVal<<endl;
//     while(curr != NULL){
//       if(flag)cout<<curr->data<<endl;
//       if(flag==false && curr->data == stNodeVal)flag = true;
//       curr = curr->next;
//     }
//     cout<<stNodeVal<<endl;
//   }
// };


/*
1. new()
2. else



1------segmentation fault becoz of not using new(), since if not use then vahi azeeb behaviour ,i.e., ek hi input leke program end, ek value hi print karke end, kabhi koi garbage value print etc etc , there exist no reason why these comes!!
(also new ka farak bahar global head, tail mai nhai , andar new node mai hai !)
2. -------new lagane ke baad bhi nahi chala becox head=head->next nahi likha tha loop mai , therefore infinite loop !
*/









class Circuit{
    public:
    // node* head = new node(); // static can be function only
    // node* tail = new node();  // no farak of this new
    node* head = NULL;
    node* tail = NULL;
    void createlist(){
        int n;
        cin >> n;
        while(n!=-1){
            if(head==NULL){
                node* new_node = new node();  // without new not working
                // node* new_node;
                new_node -> data =n;
                head = new_node;
                tail = new_node;

            }
            // else{                  ////else missing
            node* new_node = new node();
            // node* new_node;
            new_node -> data = n;
            tail -> next = new_node;
            new_node -> next = NULL;
            tail = new_node;
            // }

            cin >> n;
        }

      
    }

    void makeTheCircuit(){
        int start;
        cin >> start;
        // node* orig = head;
        while(start!=head->data){
            head = head->next;
            // cout << "Heloo"<<endl;

        }
        node* temp = new node();
        // node* temp;
        temp =  head;
        while(head!=NULL){
            cout << head -> data << endl;
            // cout << "KK";
            head = head -> next;           ///////mising

        }
        cout << temp -> data << endl;
        // head = orig;
    }

};


int main(){
    Circuit c;
    c.createlist();
    c.makeTheCircuit();
    return 0;
}