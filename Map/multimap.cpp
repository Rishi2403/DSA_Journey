#include<iostream>
#include<map>
using namespace std;

int main()
{
    multimap<string,int> directory;

    directory.insert(make_pair("rish",8456563653));
    directory.insert(make_pair("cyka",4246546358));
    directory.insert(make_pair("rish",7896485305));

    for(auto pair:directory){
        cout<<"Name -"<<pair.first<<"\n";
        cout<<"phn no -"<<pair.second<<"\n";
    }

    return 0;
}