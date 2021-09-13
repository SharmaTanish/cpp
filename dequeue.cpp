// dequeue - double ended queue

#include <iostream>
using namespace std;

class Queue{
    public:

    int front=-1;
    int rear=-1;
    int* queue = new int[50]; 
};


void insertRear(Queue &obj, int ele){
    if(obj.rear==49){
        cout << "Queue full" << endl;
        return;
    }
    if(obj.front==-1){
        obj.front++;
    }
    obj.rear++;
    obj.queue[obj.rear] = ele;
    
}

void insertFront(Queue &obj, int ele){
    if(obj.front==0){
        cout << "Cannot add in front , no space!" << endl;
        return;
    }
    if(obj.front==-1){
        obj.front+=2;
    }
    if(obj.rear==-1){
        obj.rear++;
    }
    obj.front--;
    obj.queue[obj.front] = ele;
    
}

void popFront(Queue &obj){
    if(obj.front==-1){
        cout << "Nothing to pop!" << endl;
        return;
    }

    obj.front++;  
    
}

void popRear(Queue &obj){
    if(obj.rear==-1){
        cout << "Nothing to pop!" << endl;
        return;
    }

    obj.rear--;  
    
}

void print(Queue &obj){
    for(int i=obj.front;i<=obj.rear;i++){
        cout << obj.queue[i] << " ";
    }
    cout << endl;
}


int main(){

Queue obj;

insertRear(obj,1);
insertRear(obj,2);

print(obj);

insertFront(obj,3);

print(obj);

popRear(obj);

print(obj);

popFront(obj);

print(obj);

return 0;
}

