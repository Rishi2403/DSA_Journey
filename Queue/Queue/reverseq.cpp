#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    stack<int> st;
    while(not q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(not st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(not q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}