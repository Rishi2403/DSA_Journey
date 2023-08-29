#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool checkOnetoOne(string s1, string s2){

        unordered_map<char,char> m;

        for(int i=0;i<s1.length();i++){
        if(m.find(s1[i])!=m.end()){
            if(m[s1[i]]!=s2[i]){
                return false;
            }
        }else{
            m[s1[i]]=s2[i];
        }
    }
    return true;
}

bool checkIsomorphic(string s1, string s2){

    if(s1.length()!=s2.length()){
        return false;
    }
    
    //check one to one mapping from s1 to s2
    int s1s2=checkOnetoOne(s1,s2);

    //check ono-one mapping from s2 to s1

    int s2s1=checkOnetoOne(s2,s1);

    return s1s2 && s2s1;
}

int main()
{

    string s1,s2;
    cin>>s1>>s2;
    
    cout<<(checkIsomorphic(s1,s2)? "Isomorphic ": "Not isomorphic");

    return 0;
}