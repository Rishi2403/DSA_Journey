#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_multimap<string,int> fruitcount;

    fruitcount.insert(make_pair("apple",6));
    fruitcount.insert(make_pair("watermelon",7));
    fruitcount.insert(make_pair("apple",4));

    for (auto pair : fruitcount){
        cout<<"Fruit "<<pair.first<<"\n";
        cout<<"Number "<<pair.second<<"\n";
    }

    return 0;
}