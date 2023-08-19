#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int> st;
    Queue(){}

    void push(int val){

        st.push(val);
    }
    void pop(){
        stack<int> tmp;

        while(st.size() != 1){
            tmp.push(st.top());
            st.pop();
        }
        st.pop();
        while(not tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
    }
    bool isEmpty(){
        return st.empty();
    }
    int getFront(){
        stack<int> tmp;

        while(st.size() != 1){
            tmp.push(st.top());
            st.pop();
        }
        int res=st.top();
        while(not tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
        return res;
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