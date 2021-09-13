// min priority queue
// works by adding next element as bigger than previous and not vice versa, working on same in insert function!!!!!!!!

#include <iostream>
using namespace std;

class Queue{
    public:

    int front=-1;
    int rear=-1;
    int* queue = new int[50]; 
    };


void insert(Queue &obj, int ele){
    if(obj.rear==49){
        return;
    }
    if(obj.front==-1){
        obj.front++;
        obj.rear++;
        obj.queue[obj.front]=ele;
        return;
    }
    // obj.rear++;
    // obj.queue[obj.rear] = ele;

    for(int i=obj.front;i<=obj.rear;i++){
        if(ele<obj.queue[i]){
             for(int j=obj.rear;j>=i;j--){
                 if(obj.rear<49)
                 obj.queue[j+1]=obj.queue[j];
             }
             obj.queue[i]=ele;
             obj.rear++;
             return;
        }
        
        // if(i==obj.rear){
        //     obj.rear++;
        //     obj.queue[obj.rear]=ele;
            
        // }
    }
    
}

void pop(Queue &obj){
    if(obj.front==-1){
        return;
    }

    obj.front++;
    
    
}

void print(Queue &obj){
    for(int i=obj.front;i<=obj.rear;i++){
        cout << obj.queue[i] << " ";
    }
    cout << endl;
}

int getMin(Queue &obj){
    if(obj.front!=-1)
    return obj.queue[obj.front];
    else return -1000;
}

int main(){

Queue obj;

insert(obj,6);
insert(obj,5);
insert(obj,4);
insert(obj,3);
insert(obj,2);

print(obj);

insert(obj,1);

print(obj);

pop(obj);

print(obj);

cout << getMin(obj) << endl;

return 0;
}

