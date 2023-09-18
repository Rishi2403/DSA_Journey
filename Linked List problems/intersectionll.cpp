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
//int Getlength(Node* head);
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


 int GetLength(Node* head)
{
    Node* temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;

}


Node* GetMovedByk(Node* head,int k)
{
    Node* ptr=head;
    while(k>0)
    {
        ptr=ptr->next;
        k--;
    }

    return ptr;
}


Node* IntersectionLinkedList(Node* head1, Node* head2)
{
    Node* ptr1=head1;
    Node* ptr2=head2;
    //step 1 - to find the length of linkedlist
    int l1=Getlength(head1);
    // int len=0;
    // while(head1!=NULL)
    // {
    //     len++;
    //     head1=head1->next;
    // }
    
    int l2=GetLength(head2);

    // int len1=0;
    // //int len=0;
    // while(head2!=NULL)
    // {
    //     len1++;
    //     head2=head2->next;
    // }

    //step2- move the head pointer of larger linked list so that each linked list from their respective head is equal
    
    if(l1>l2)
    {
        int k=l1-l2;
        ptr1=GetMovedByk(head1,k);
        ptr2=head2;
    }
    else{
        int k=l1-l2;
        ptr1=head1;
        ptr2=GetMovedByk(head2,k);
        
    }
    //compare ptr1 and ptr to find the intersection

    while(ptr1)
    {
        if(ptr1==ptr2)
        {
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;


    }
    return NULL;

}

int main() {
    int x;
    LinkedList ll;
    for (int i=0;i<5;i++)
    {   cin>>x;
        ll.insertAtTail(x);
    }
    ll.Display();
    
    LinkedList l2;
    l2.insertAtTail(6);
    l2.insertAtTail(7);
    //l2.insertAtTail(3);
    //l2.insertAtTail(4);
    l2.head->next->next=ll.head->next->next->next;
    l2.Display();

    cout<<IntersectionLinkedList(ll.head,l2.head);


return 0;
}