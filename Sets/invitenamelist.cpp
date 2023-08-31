#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<string> namelist; int n;
    cout<<"Enter no of names"<<"\n";
    cin>>n;
    while(n--){
        string name;
        cin>>name;
        namelist.insert(name);
    }
    cout<<"The names in order are"<<"\n";
    for(auto name: namelist){
        cout<<name<<endl;
    }
    return 0;
}