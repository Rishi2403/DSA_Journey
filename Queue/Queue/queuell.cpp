#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    int size;
    Node(int val)
    {
        data=val;
        next=NULL;
        size=0;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void enqueue(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
        this->size++;
    }
    void dequeue(){
        if(head==NULL)
        return;
        else{
            Node* oldHead=head;
            Node* newhead=head->next;
            head=newhead;
            if(head==NULL) tail=NULL;
            oldHead->next=NULL;
            delete oldHead;
            this->size--;
        }
    }
        int getsize(){
            return size ;
        }
        bool isEmpty(){
            return this->head==NULL;
        }
        int front(){
            if(head==NULL)return -1;
            else{
                return head->data;
            }
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
    //cout<<q.front();

    while (not q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.dequeue();
    }
    
    return 0;
}