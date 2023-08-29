#include<iostream>
#include<stack>
using namespace std;

//method 2- Recursive approach
void f(stack<int> &st, stack<int> &res)
{
    if(st.empty()) return;
    int curr=st.top();
    st.pop();
    f(st,res);
    res.push(curr);
}
int main()
{
    stack<int> st;
    //stack<int> temp;
    //stack<int> copy;
    cout<<"Original stack"<<"\n";
    for(int i=1;i<=4;i++)
    {
        st.push(i);
        //cout<<st.top()<<"\n";
    }
    stack<int> res;
    f(st,res);
    //first iterative method by me(ALgorithm is just extract one ele from st and put in temp... tht will result in reverse order order and if we again store it in another stack it will store it as the original order.)
    // for(int i=1;i<=4;i++)
    // {           
    //     cout<<st.top()<<"\n";
    //     break;
    //     //st.pop();
    // }
    // for(int i=1;i<=4;i++)
    // {           
    //     int x=st.top();
    //     st.pop();
    //     temp.push(x);       
    // }
    // cout<<"Temporary  stack"<<"\n";
    // for(int i=1;i<=4;i++)
    // {           
    //     cout<<temp.top()<<"\n";
    //     break;
    //    // temp.pop();
    // }
    // for(int i=1;i<=4;i++)
    // {           
    //     int x=temp.top();
    //     temp.pop();
    //     copy.push(x);       
    // }
    //    cout<<"Copied  stack"<<"\n";
    for(int i=1;i<=4;i++)
    {           
        cout<<res.top()<<"\n";
        res.pop();
    }
  
    return 0;
}