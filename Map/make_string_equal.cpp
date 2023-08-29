#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool canMakeEqual(vector<string> &v){
    unordered_map<char,int> m;

    for (auto str:v){
        for(char c:str){ // keeping the frequency of each charactor in the vector of string
            m[c]++;
        }
    }

    int n=v.size();
    for(auto ele:m){
        if(ele.second%n !=0){ // if the characters are multiples of vvector size
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n; // the limit of vector

    vector<string> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int x=canMakeEqual(v);
    if (x==1){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No "<<"\n";
    }

    return 0;
}