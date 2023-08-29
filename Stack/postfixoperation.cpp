#include<iostream>
#include<math.h>
#include<stack>
#include<string>
using namespace std;

int calc(int v1, int v2,char op){
    if (op=='^')
    return pow(v1,v2);
    else if (op=='*')
    return v1*v2;
    else if(op=='/')
    return v1/v2;
    else if (op=='-')
    return v1-v2;
    else
    return v1+v2;
}
int eval(string &str)
{
    stack<int> st;
    for (int i=0;i<str.length();i++){
        char ch=str[i];

        if(isdigit(ch)){
            st.push(ch-'0');
           // cout<<st.top()<<"\n";            
        }
        else{
            int v2=st.top();
            st.pop();
            int v1=st.top();
            st.pop();
           // cout<<calc(v1,v2,ch)<<" ";
            st.push(calc(v1,v2,ch));
            cout<<st.top()<<"\n"; 
        }
    } return st.top();
}

int main()
{
    string s ="231*+9-";
    //cout<<s.size()<<"\n";
    cout<<eval(s);
    return 0;
}