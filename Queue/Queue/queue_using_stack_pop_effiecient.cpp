#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int> st;
    Queue(){}

    void push(int val){

        stack<int> tmp;
        while(not st.empty()){
            tmp.push(st.top());
            st.pop();
        }
        st.push(val);

        while(not tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
    }

    void pop(){
        if (st.empty()) return;
        st.pop();
    }

    bool isEmpty(){
        return st.empty();
    }
    int getFront(){
        return st.top();
    }
};

int main()
{
    Queue qu;
    
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();

    while (not qu.isEmpty())
    {
        cout<<qu.getFront()<<" ";
        qu.pop();
    }
    
    return 0;
}