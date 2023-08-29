#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextgreaterelement(vector<int> &arr){
    int n=arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for (int i=1;i<n;i++){
        while (!st.empty() and arr[i]>arr[st.top()])
        {
            output[st.top()]=arr[i];
            st.pop();
        }st.push(i);        
    }
    while(not st.empty()){  //not mandatory
        output[st.top()]=-1;
        st.pop();
    }
    return output;
}
int main()
{
    vector<int> arr{4,3,9,1,6,8,2};
    vector<int> res=nextgreaterelement(arr);
    for(int i=0;i<7;i++)
    {
        cout<<res[i]<< " ";
    }
    return 0;
}