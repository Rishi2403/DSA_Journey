#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data) {
        val=data;
        next=NULL;
        prev=NULL;
    }

};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;
    }

    void display()
    {
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;
    }

    void insertAtStart(int val){
        Node* new_node=new Node(val);

        if (head==NULL){
            tail=new_node;
            head=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }
    void insertAtEnd(int val){
         Node* new_node=new Node(val);

        if (tail==NULL){
            tail=new_node;
            head=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    void insertAtKth(int val,int k)
    {
        Node* new_node=new Node(val);
        Node* temp;
        temp=head;
        int count=0;
        while(count<k-2)
        {
            temp=temp->next;
            count+=1;
        }
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        new_node->prev=temp;
        
    }
    void deleteAtFirst()
    {
        if(head==NULL)
        {
            return;
        }
        Node *temp=head;
        head=head->next;
        if(head==NULL)
        {
            tail=NULL;
        }
        else{
            head->prev=NULL;
        }
        free(temp);
        return;
    }
    void deleteAtEnd()
    {
        if(head==NULL)
        {
            return;
        }
        Node* temp=tail;
        tail =tail->prev;
        if(tail==NULL)
        {
            head=NULL;
        }
        else{
            tail->next=NULL;            
        }
        free(temp);
        return;
    }

};

int main()
{
    Node* new_node= new Node(3);

    DoublyLinkedList dll;
    // dll.head=new_node;
    // dll.tail=new_node;
    // cout<<dll.head->val<<endl;
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(3);

    dll.insertAtEnd(5);
    dll.insertAtKth(9,3);
    dll.deleteAtFirst();
    dll.display();
    dll.deleteAtEnd();
    dll.display();
    return 0;
}