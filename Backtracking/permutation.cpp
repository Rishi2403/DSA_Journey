#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void permutation(string &str, int i,set<string> &s){
    //base case 
    if(i==str.size()){
       // cout<<str<<"\n";
       s.insert(str);
       //cout<<s.begin();
        return;
    }
    for (int j=i;j<str.size();j++){
        swap(str[i],str[j]);
        permutation(str,i+1,s);
        swap(str[i],str[j]);
    }
}

int main()
{
    string str;
    cin>>str;
    set<string> s;
    permutation(str,0,s);

    // for(int i=0;i<s.size();i++){
    //     cout<<s<<"\n";
    // }
    for(auto val: s){
        cout<<val<<endl;
    }
    return 0;
}