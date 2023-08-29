#include<iostream>
#include<stack>
using namespace std;

class Minstack{
    public:
    stack<int> st;
    int mn;

    Minstack(){
        mn=1000;
    }
    void push(int val){
        if(st.empty()){
            mn=val;
            st.push(val);
        }
        else{
            st.push(val-mn);
            if(mn>val){
                mn=val;
            }
        }
    }
    void pop(){
        if(not st.empty()){
        if(st.top()>=0){
            st.pop();
        }
        else{
            mn=mn-st.top();
            st.pop();
        }
    }}
    int top(){
        if(st.size()==1)
        return st.top();
        else if(st.top()<0){
            return mn;
        }
        else{
            return mn+st.top();
        }
    }
    int Getmin(){
        return mn;
    }
};

int main()
{    
    Minstack m;
    m.push(10);
    m.push(5);
    m.push(6);
    m.push(12);
    m.push(-1);
    cout<<m.top()<<endl;
    m.pop();

    cout<<m.Getmin()<<"\n";

    return 0;
}