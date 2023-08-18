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
void reverseorder(Node* &head)
{
    //base condition
    if(head==NULL) {
        
        return;       
    }

    reverseorder(head->next);
    cout<<head->val<<"->";

}
cout<<"NULL"<<endl;
int main() {
    int x;
    LinkedList ll;
    for (int i=0;i<5;i++)
    {   cin>>x;
        ll.insertAtTail(x);
    }
    ll.Display();
    reverseorder(ll.head);
    //ll.Display();
    // ll.insertAtTail(1);
    // ll.insertAtTail(2);
    // ll.insertAtTail(3);
    // ll.insertAtTail(4);
    // ll.Display();

return 0;
}