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

Node* rotatebyk(Node* head, int k)
{
    // Find n
    int n=0;
    //find tail node
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
        n++;
    }
    n++;
    tail->next=head;

    //traverse n-k nodes
    Node* temp=head;
    for(int i=1;i<n-k;i++)
    {
        temp=temp->next;
    }
    Node* new_head=temp->next;
    temp->next=NULL;

    return new_head;
    

}

int main() {
    int x;
    //cin>>x;
    LinkedList ll;
    // while(x!=0)
    // {   cin>>x;
    //     ll.insertAtTail(x);
    // }
    // ll.Display();
    // ll.head=(ll.head);
    // ll.Display();
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.Display();
    ll.head=rotatebyk(ll.head,5);
    ll.Display();
    //ll.Display();

return 0;
}