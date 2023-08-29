#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int histogram(vector<int> &arr){
    int n=arr.size();
    int ans=0;
    stack<int> st;
    st.push(0);
    for (int i=1;i<n;i++){
        while (!st.empty() and arr[i] < arr[st.top()])
        {
            int el=arr[st.top()];   //curr bar to removed and calculated
            st.pop();
            int nsi=i;
            int psi=(st.empty())? -1 : st.top();
            cout<<el<<" "<<nsi<<" "<<psi<<"\n";
            ans=max(ans, el*(nsi-psi-1));            
        }st.push(i);        
    }
    while(not st.empty()){  //not mandatory    
            int el=arr[st.top()];
            st.pop();
            int nsi=n;
            int psi=(st.empty())? -1 : st.top();
            cout<<nsi<<" "<<psi<<" "<<el<<"\n";
             ans=max(ans, el*(nsi-psi-1));            
    }
    return ans;
}

int main()
{
    vector<int> v{2,1,5,6,2,3,0,2,1,10,11,2,3};
    cout<<histogram(v)<<"\n";
    return 0;
}