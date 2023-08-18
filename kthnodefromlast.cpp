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

void kthnodefromlast(Node* head,int k)
{
    Node* ptr1=head;
    //Node* ptr2=head;

    //will make another pointer which is k distance from it.
    while(k>0)
    {
        head=head->next;
        k--;
    }
    Node* ptr2=head;

    //Now will move both pointer till the ptr2 reaches null so that the ptr1 will point to the node to be deleted
    while(ptr2->next != NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    Node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}


int main() {
    int x;
    cin>>x;
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
    ll.Display();
    //ll.head=reversellrecursion(ll.head);
    kthnodefromlast(ll.head,x);
    ll.Display();

return 0;
}