#include<iostream>
#include<vector>
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

Node* mergesortlinkedlist(Node* &head1,Node* &head2)
{
    Node* dummyhead=new Node(-1);

    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* ptr3=dummyhead;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->val < ptr2->val)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else if(ptr1->val > ptr2->val)
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1!=NULL)
    {
        while (ptr1!=NULL)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        
    }
    if(ptr2!=NULL)
    {
        while (ptr2!=NULL)
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        
    }
    return (dummyhead->next);
}

Node* mergeklinkedlist(vector<Node*> &lists)
{
    while(lists.size()>1)
    {
        Node* mergedhead=mergesortlinkedlist(lists[0],lists[1]);
        lists.push_back(mergedhead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());

    }
    return lists[0];
}
//vector 1 -> head1 head2 head3 head4
// head1 and head2 will be merged
//head3 head4 mergedhead1_2
// head3 and head4 will get merged
//mergedhead1_2 mergedhead3_4
//mergedhead1_2_3_4

int main() {
    int x;
    LinkedList ll;
    // for (int i=0;i<5;i++)
    // {   cin>>x;
    //     ll.insertAtTail(x);
    // }
    //ll.Display();
    //reverseorder(ll.head);
    //ll.Display();
    ll.insertAtTail(1);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.Display();
    
    LinkedList ll2;

    ll2.insertAtTail(2);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    ll2.Display();

    LinkedList ll3;

    ll3.insertAtTail(3);
    ll3.insertAtTail(6);
    ll3.insertAtTail(12);
    ll3.Display();

    vector <Node*> lists;

    lists.push_back(ll.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    
    LinkedList llmergedhead;

    llmergedhead.head=mergeklinkedlist(lists);
    llmergedhead.Display();



return 0;
}