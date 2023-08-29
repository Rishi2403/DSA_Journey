#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxsubarray(vector<int> &v){

    unordered_map<int,int> m;
    int prefixsum=0;
    int maxlen=0;
    for(int i=0;i<v.size();i++){

        prefixsum+=v[i];

        if(prefixsum==0){
            maxlen++;
        }

        if(m.find(prefixsum)!=m.end()){
            maxlen=max(maxlen,i-m[prefixsum]);
        }else{
            m[prefixsum]=i;
        }
    }
    return maxlen;
}

int main()
{
        int n;
    cin>>n; // the limit of vector

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxsubarray(v)<<"\n";

    return 0;
}