#include <iostream>
using namespace std;

class Queue{
    public:

    int front=-1;
    int rear=-1;
    int* queue = new int(5);  
    bool secondRound=false;
    };


void insert(Queue &obj, int ele){
    if(obj.secondRound){
        int temp=obj.rear+1;
        if(temp>=obj.front){
            return;
        }
    }

    if(obj.rear==4){
        // return;
        // circular queue use here

        if(obj.front!=0 ){
                // means space there exist in front end, hence can insert element over there
                    if(obj.secondRound==false){
                    obj.rear=0;
                    obj.secondRound=true;
                    }
                    else{
                        return;
                    }

                obj.queue[obj.rear]=ele;  
                return; 
        }
        else{
            return;
        }

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
    if(!obj.secondRound){
    for(int i=obj.front;i<=obj.rear;i++){
        cout << obj.queue[i] << " ";
    }
    }
    else{
        for(int i=obj.front;i<=4;i++){
        cout << obj.queue[i] << " ";
    }
        for(int i=0;i<=obj.rear;i++){
        cout << obj.queue[i] << " ";
    }
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

insert(obj,6);

print(obj);

insert(obj,7);

print(obj);



return 0;
}

