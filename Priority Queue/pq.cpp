#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq1;
    pq1.push(5);
    pq1.push(4);
    pq1.push(54);
    pq1.push(7);
    pq1.push(2);
    cout<<"Max Heap"<<'\n';

    while(!pq1.empty()){
        cout<<pq1.top()<<"\n";
        pq1.pop();
    }

    return 0;
}