#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> stockspan(vector<int> &arr){
    int n=arr.size();
    reverse(arr.begin() , arr.end());
    
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for (int i=1;i<n;i++){
        while (!st.empty() and arr[i]>arr[st.top()])
        {
            output[st.top()]=n-1-i;
            st.pop();
        }st.push(i);        
    }
    while(not st.empty()){  //not mandatory
        output[st.top()]=-1;
        st.pop();
    }
    reverse(output.begin() , output.end());
    reverse(arr.begin(),arr.end());
    return output;
}

int main()
{
    vector<int> v{100,80,60,70,60,75,85};
    vector<int> res=stockspan(v);

     for(int i=0;i<7;i++)
    {
        cout<<i-res[i]<< " ";
    }
    return 0;
}