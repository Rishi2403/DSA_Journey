#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int d){
        val=d;
        next=NULL;
    }
};
class Stack{
   
   Node* head;
   int capacity;
   int top;
   public:
   Stack(int c){
    capacity=c;
    head=NULL;
    top=0;
   }
   void push(int d)
   {
    Node* newnode=new Node(d);
    //newnode->val=d;

    if(top==capacity)
    {
        cout<<"Overflow"<<"\n";
        return;
    }
    newnode->next=head;
    top++;
    head=newnode;
   }
   void pop()
   {
    Node* temp;
    temp=head;   
    if (head==NULL)
    {
        cout<<"Underflow"<<"\n";
    }
    head=head->next;
    top--;
    free(temp);
   }
   int gettop()
   {
    return head->val;
   }

};

int main()
{
    
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.gettop()<<"\n";
    st.pop();
    cout<<st.gettop()<<"\n";

    return 0;
}