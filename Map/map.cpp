#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> directory;

    directory["Rishi"]=6846486;
    directory["suhani"]=88796547;
    directory["didi"]=756765108;

    for(auto element: directory){
        cout<<"Name - "<<element.first<<"\n";
        cout<<"Phn no -"<<element.second<<"\n";
    }

    return 0;
}