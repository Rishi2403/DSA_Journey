#include<iostream>
#include<stack>
using namespace std;

void removeAtbottom(stack<int> &st){
    stack<int> temp;
    int n=st.size();
    while (st.size() != 1)
    {
        int x=st.top();
        st.pop();
        temp.push(x);
    }
    st.pop();
    while(not temp.empty())
    {
        int y=temp.top();
        temp.pop();
        st.push(y);
    }
    
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    removeAtbottom(st);
    while(not st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}