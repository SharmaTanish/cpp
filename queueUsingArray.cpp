#include <iostream>
using namespace std;

class Queue{
    public:

    int front=-1;
    int rear=-1;
    int* queue = new int[50];  // int* use karke , ham kisi function se array as int* return bhi karva sakte hai ,i.e., pointer and int arr[] can be easily directly interconverted, if take directly int queue[50] the can't store returned pointer in this queue (error)
};


void insert(Queue &obj, int ele){
    if(obj.rear==49){
        return;
    }
    if(obj.front==-1){
        obj.front++;
    }
    obj.rear++;
    obj.queue[obj.rear] = ele;
    
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


int main(){

Queue obj;

insert(obj,1);
insert(obj,2);
insert(obj,3);
insert(obj,4);
insert(obj,5);

print(obj);

insert(obj,6);

print(obj);

pop(obj);

print(obj);

return 0;
}

