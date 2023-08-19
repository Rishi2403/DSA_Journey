#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int rear;
    vector<int> v;
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    void enqueue(int m){
        if(front==-1 and rear==-1){
            front=0;
            rear=0;
            v.push_back(m);
           // rear++;
        }
        else{
            v.push_back(m);
            rear++;
        }
    }
    void dequeue(){
        if(front==rear){
            front=-1;
            return;
        }
        else{
            front++;
        }
        
    }
    int getfront(){
        return v[front];
    }
    bool isEmpty(){
        return this->front==-1;
    }

};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(80);
    q.dequeue();
    q.enqueue(5);
    q.dequeue();
    //cout<<q.front();

    while (not q.isEmpty())
    {
        cout<<q.getfront()<<" ";
        q.dequeue();
    }
    

    return 0;
}