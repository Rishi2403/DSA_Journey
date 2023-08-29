#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

bool checkAnagram(string a, string b){

    
    unordered_map<char,int> m;
    //int c;
    //char c;
        for(auto c1:a){ // keeping the frequency of each charactor in the vector of string
            m[c1]++;
        }
        

        for(auto c2:b){ // keeping the frequency of each charactor in the vector of string
            if(m.find(c2)==m.end()){
                return false;
            }else{
                m[c2]--;
            }
        }

        for(auto ele:m){
            if(ele.second!=0)
            return false;
        }

        return true;
}

int main()
{
    string a,b;
    cout<<"Enter two strings"<<"\n";
    cin>>a>>b;

        //cout<<m.size()<<endl;
    cout<<(checkAnagram(a,b)? "Anagram " : " No Anagram")<<"\n";

    return 0;
}