#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int data) {
        val=data;
        next=NULL;
    }

};

// class Node()
// {
//     public:                       
//         Node* next;
//         int val;
//         Node(int data)
//         {
//             next=NULL;
//             val=data;
//         }
// };
class LinkedList{

    public:
        Node* head;

        LinkedList()
        {
            head=NULL;
        }

        void insertAtTail(int val){
       
            Node* new_node= new Node(val);

            if(head==NULL){
                head=new_node;
                return;
            }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;

    }
    void Display(){
        
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;

    }

};

Node* reversekll(Node* &head , int k){
    Node* prevptr=NULL;
    Node* currptr=head;

    int counter=0;
    while(currptr!=NULL && counter<k){ //reversing k nodes
        Node* nextptr=currptr->next;
        currptr->next=prevptr;
        currptr=nextptr;
        counter++;
    }
    //currptr will return k+1 node
    if(currptr!=NULL){
        Node* new_head=reversekll(currptr,k);
        head->next=new_head;
    }

    return prevptr;// will return the new head of connected linked list
}

int main() {
    int x;
    LinkedList ll;
    for (int i=0;i<5;i++)
    {   cin>>x;
        ll.insertAtTail(x);
    }
    ll.Display();
    ll.head=reversekll(ll.head,2);
    ll.Display();
    // ll.insertAtTail(1);
    // ll.insertAtTail(2);
    // ll.insertAtTail(3);
    // ll.insertAtTail(4);
    // ll.Display();

return 0;
}