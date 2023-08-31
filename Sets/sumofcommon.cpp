#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> v1(n);
    vector<int> v2(m);

    cout<<"Enter the elements for first vector";
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    cout<<"enter elements fr second vector";
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }
    set<int> s1;
    for(int i=0;i<n;i++){
        s1.insert(v1[i]);
    }
    // set<int> s2;
    // for(int i=0;i<m;i++){
    //     s2.insert(v2[i]);
     int s=0;
    for(int i=0;i<m;i++){
        if(s1.find(v2[i])!=s1.end()){
            s=s+v2[i];
        }
    }
    cout<<"The sum is "<<s<<"\n";

    return 0;
}