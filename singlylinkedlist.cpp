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
void insertAtHead(Node* &head, int val){
    Node* new_node =new Node(val);
    new_node->next=head; // to point the current linked list starting point
    head=new_node; // to insert at the starting of an element
}

void insertAtTail(Node* &head, int val){
    Node* new_node =new Node(val);
    Node* temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;
}

void insertAtPosition(Node* &head , int val, int pos){

    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    Node* new_node= new Node(val);
    Node* temp=head;
    int current_pos=0;
    while(current_pos != pos-1){
        temp=temp->next;
        current_pos++;
    }
    //temp is pointing to pos-1

    new_node->next=temp->next;
    temp->next=new_node;
}

void Update(Node* &head,int val, int pos){

    Node* new_node= new Node(val);
    Node* temp=head;
    int current_pos=0;
    while(current_pos != pos){
        temp=temp->next;
        current_pos++;
    }
    temp->val=val;

}

void deleteAtHead(Node* &head)
{
    Node* temp=head; //node to be deleted
    head=head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    
    Node* second_last=head;

    while(second_last->next->next !=NULL){
        second_last=second_last->next;
    }
    Node* temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}

void deleteAtPosn(Node* &head,int pos){
    if (pos==0){
        deleteAtHead(head);
        return;
    }
Node* prev=head;
int current_pos=0;
while(current_pos!=pos-1){
    prev=prev->next;
    current_pos++;
}
Node* temp=prev->next;
prev->next=prev->next->next;
free(temp);

}

void display(Node* head){

    Node* temp=head;
    while(temp!=NULL){

        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {

    Node* head =NULL;
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,3);
    insertAtHead(head,4);
    display(head);
    insertAtTail(head,9);
    display(head);
    insertAtPosition(head,8,4);
    display(head);
    Update(head,5,2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtPosn(head,2);
    display(head);

    //Node* n=new Node(1);
    //cout<<n->val <<" "<<n->next <<endl;
    
return 0;
}