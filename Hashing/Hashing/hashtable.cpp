#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Hashing{
    vector<list<int>> hashtable;
    int buckets;
    public:
    Hashing(int size){
        buckets=size;
        hashtable.resize(size);
    }
    int hashvalue(int key){
        return key%buckets; // division method
    }
    void add(int key){
        int idx=hashvalue(key);
         hashtable[idx].push_back(key);
    }

    list<int>::iterator search (int key){
        int idx=hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);        
    }
    void del(int key){
        int idx=hashvalue(key);
        if(search(key)!=hashtable[idx].end()){
            hashtable[idx].erase(search(key));
            cout<<key<<" is deleted"<<"\n";
        }else{
            cout<<"Key not found "<<"\n";
        }
    }
};

int main()
{
    Hashing h(10);
    h.add(15);
    h.add(565);
    h.add(87);
    h.del(565);

    return 0;
}