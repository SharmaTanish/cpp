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
// OR HERE CAN MAKE ARR LIKE SIMPLE ONLY, i.e., int arr[size] ( taking elements of arr via input not directly {1,52,6,....} ) , AND PASS JUST arr AS ARGUMENT TO FUNCTION , AND THERE GET THIS BY SIMPLE int arr[] , AND NO NEED TO RETURN ANYTHING THE GLOBAL ARR WILL AUTOMATCALLY EFFECTED , SINCE int arr[] IS BY-DEFAULT POINTER ONLY, i.e.,
/*
array ke case me upr-upr se dekhe to kaam ek hi hai bs agr pointer se krte hn to ek alg se pointer bn jata hai jo ki point krta hai apne array ke first element ko aur agr arr[] aise bnaye to isme array ka address khud hi arr[0] ke equal hota hai like 

int arr[] = {1,2,3};  
-> isme agr aap print kro , " arr , &arr , &arr[0] " to ye tino same aayenge but

int* arr = new int[3];
arr[0] = 1;
-> isme agr aap " arr , &arr , &arr[0] " print kro to alg aayega arr , &arr ka address kyoki &arr real pointer ka address dega jo create hua aur khaali arr dega *arr ka mtlb 1st element ka 

aur baaki pointers ka apna use hai by reference pass , allocate krni ho memory baaki apna ye data structures me..............
*/
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

