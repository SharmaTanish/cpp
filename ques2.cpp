// In an university , the library opens at 10:00 AM. At the time of opening , 
// 5 students are there named as A,B,C,D,E. Then lib... told that these students 
// are told to make a queue as their name appears in english dictionary. It takes 
// 5 minutes to issue a book. After each issue , a student has to come out from the
// queue , after each 10 minutes , a new student is joined with old students , so 
// likewise 5 new students will be inserted P,Q,R,S,T and they have to come as per
// the order in english dictionary , so , display the queue i.e, display the names
// of the students who are present at 10:50 AM and also display the queue elements 
// , after 10 minute of interval from starting time 10:00 AM. (par leave queue maise FIFO fashion mai hi hoga!)

// university -> lib (10 bje) -> library sir --> open -> 5bche aaye the -> libry 
// sir bole a,b,c,d,e aaye the -> tum queue me khde ho as per english dic -> libry
// sir 5 minute to process 1 book -> 1 book process ke baad student chla jaata
// hai -> hr 10 minute me ek nya student queue me ghusta hai -> so max. to max.
// if we will insert 5 students -> total students in and out = 10 students will
// be processed -> 10 stude. ko book mil skta hai -> 10:50 pr display krna hai
// queue me kon-kon hai -> last 5 bche aayenge vo hn p,q,r,s,t -> hr 10 min.
// pr btao queue me konsa element hai , 10:50 pr kon hai timing ko loop me
// mt lo phle reasoning ki trha krlo kon kon aayega hr 10 min. me to fir
// cout me likhna hai at 10 am , at 10:10 pr ye , at 10:20 pr ye and 10:50 
// pr ye students timing factor ko program me nhi lena , sirf queue ko
// display krna hai kon-kon hai queue me

//incomplete

#include <iostream>
#include <string.h>
using namespace std;

class Queue{
    public:

    int front=-1;
    int rear=-1;
    string* queue = new string[50]; 
    };


void insert(Queue &obj, string ele){
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

string getFront(Queue &obj){
    if(obj.front!=-1)
    return obj.queue[obj.front];
    else return "0";
}

int main(){

Queue obj;

insert(obj,"A");
insert(obj,"B");
insert(obj,"C");
insert(obj,"D");
insert(obj,"E");

print(obj);

// insert(obj,"P");

// print(obj);

// pop(obj);

// print(obj);

// cout << getFront(obj) << endl;

return 0;
}

