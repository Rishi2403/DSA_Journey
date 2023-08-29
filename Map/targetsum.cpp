#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> targetsumpair(vector<int> &v , int targetsum){

    unordered_map<int,int> m;
    vector<int> ans(2,-1);
    for(int i=0;i<v.size();i++){
        if(m.find(targetsum-v[i])!=m.end()){
            ans[0]=m[targetsum-v[i]];
            ans[1]=i;
        }else{
            m[v[i]]=i;
        }
    }
    return ans;
}

int main()
{   int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target_sum;
    cin>>target_sum;

    vector<int> ans=targetsumpair(v,target_sum);

    cout<<ans[0]<<" , "<<ans[1]<<"\n";


    return 0;
}