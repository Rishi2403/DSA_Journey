#include <iostream>
using namespace std;

class Stack{
    int container;
    int top;
    int* stk;
    public:
    Stack(int c){
        container=c;
        top=-1;
        stk=new int[c];
    }
    void push(int d)
    {
        if(top==container){
            cout<<"Overflow"<<"\n";
            return;
        }
        top++;
        stk[top]=d;
    }
    void pop()
    {
        if (top==-1)
        {
            cout<<"Underflow"<<"\n";
            return;
        }
        top--;
        cout<<stk[top]<<"\n";
    }
    int gettop()
    {
        return stk[top];
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