#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> set1;
    set1.insert(1);
    set1.insert(9);
    set1.insert(8);
    set1.insert(4);

    // set<int>::iterator itr;
    // for (int itr=set1.begin() ; itr!=set1.end() ; itr++){
    //     cout<<itr <<" ";
    // }cout<<"\n";
    for (auto value : set1){
        cout<<value<<" ";
    }

    return 0;
}