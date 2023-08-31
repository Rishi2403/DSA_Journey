#include<iostream>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

bool checkAlphabets(string s){
    if (s.size()<26){
        return false;
    }
    
    transform(s.begin(), s.end(), s.begin() ,::tolower );

    set<char> alphabets;
    for(auto ch: s){
        alphabets.insert(ch);
    }

    return (alphabets.size()==26);
}

int main()
{
    string s;
    cin>>s;

    cout<<checkAlphabets(s);
    return 0;
}